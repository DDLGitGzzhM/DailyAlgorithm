package gzmcall

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

// Lang 表示目标语言。
type Lang int

const (
	LangUnknown Lang = iota
	LangCPP
	LangGo
)

// ParseLang 解析语言参数（cpp / c++ / go）。
func ParseLang(s string) (Lang, error) {
	switch strings.ToLower(strings.TrimSpace(s)) {
	case "cpp", "c++":
		return LangCPP, nil
	case "go":
		return LangGo, nil
	default:
		return LangUnknown, NewUsageError("不支持的语言 %q，请使用 cpp 或 go", s)
	}
}

// Runner 负责编译与运行。
type Runner struct {
	WorkspaceRoot string
	GXX           string
	Stdout        *os.File
	Stderr        *os.File
}

// NewRunner 根据任意路径解析工作区（源码应位于工作区内）。
func NewRunner(anyPath string) (*Runner, error) {
	dir := anyPath
	if st, err := os.Stat(anyPath); err == nil && !st.IsDir() {
		dir = filepath.Dir(anyPath)
	}
	root, err := ResolveWorkspaceRoot(dir)
	if err != nil {
		return nil, err
	}
	if err := EnsureWorkspaceLayout(root); err != nil {
		return nil, err
	}
	gxx := ResolveGXX()
	return &Runner{
		WorkspaceRoot: root,
		GXX:           gxx,
		Stdout:        os.Stdout,
		Stderr:        os.Stderr,
	}, nil
}

// RunCLI 执行子命令：run | check | new。
func RunCLI(args []string) error {
	if len(args) == 0 || args[0] == "-h" || args[0] == "--help" {
		return NewUsageError(usageText())
	}
	if len(args) < 3 {
		return NewUsageError(usageText())
	}
	lang, err := ParseLang(args[0])
	if err != nil {
		return err
	}
	cmd := strings.ToLower(strings.TrimSpace(args[1]))
	fileArg := args[2]
	switch cmd {
	case "run":
		return runCmd(lang, fileArg, false)
	case "check":
		return runCmd(lang, fileArg, true)
	case "new":
		return newCmd(lang, fileArg)
	default:
		return NewUsageError("未知子命令 %q，支持 run / check / new", args[1])
	}
}

func usageText() string {
	return `用法:
  gzm-call <cpp|go> run   <源文件路径>
  gzm-call <cpp|go> check <源文件路径>
  gzm-call <cpp|go> new   <文件名或路径>

说明:
  - 用户代码与 io_cases 默认放在仓库的 workspace/ 目录；new 会在该工作区下创建文件。
  - run / check 的相对路径默认相对 workspace/ 解析（与 new 一致）；绝对路径按原样使用。
  - 也可通过环境变量指定工作区根目录（需包含 io_cases）。

环境变量:
  GZM_CALL_WORKSPACE / GZM_CALL_ROOT  强制指定工作区根目录
  GZM_CALL_GXX        C++ 编译器，默认优先 g++-7，否则自动选用 GNU G++ 7.3.0+（-std=gnu++17）`
}

func runCmd(lang Lang, file string, withCases bool) error {
	path, err := normalizeSourcePath(lang, file)
	if err != nil {
		return err
	}
	if _, err := os.Stat(path); err != nil {
		return fmt.Errorf("源文件: %w", err)
	}
	rn, err := NewRunner(path)
	if err != nil {
		return err
	}
	bin, err := rn.build(lang, path)
	if err != nil {
		return err
	}
	if !withCases {
		return rn.exec(bin, path, os.Stdin, rn.Stdout, rn.Stderr)
	}
	inPath, outPath, err := CasePaths(rn.WorkspaceRoot, path)
	if err != nil {
		return err
	}
	if _, err := os.Stat(inPath); err != nil {
		return fmt.Errorf(
			"缺少输入文件 %s（check 需要 io_cases 下与源码同名的 .in/.out，可用 new 自动创建）: %w",
			inPath, err,
		)
	}
	if _, err := os.Stat(outPath); err != nil {
		return fmt.Errorf(
			"缺少期望输出 %s（check 需要 io_cases 下与源码同名的 .in/.out，可用 new 自动创建）: %w",
			outPath, err,
		)
	}
	inFile, err := os.Open(inPath)
	if err != nil {
		return err
	}
	defer inFile.Close()
	var buf bytes.Buffer
	if err := rn.exec(bin, path, inFile, &buf, rn.Stderr); err != nil {
		return err
	}
	if err := CompareOutputs(buf.Bytes(), outPath); err != nil {
		return err
	}
	fmt.Fprintln(rn.Stdout, "check 通过：输出与", outPath, "一致")
	return nil
}

func newCmd(lang Lang, file string) error {
	wd, err := os.Getwd()
	if err != nil {
		return err
	}
	ws, err := ResolveOrCreateWorkspace(wd)
	if err != nil {
		return err
	}
	out := file
	if !filepath.IsAbs(out) {
		out = filepath.Join(ws, filepath.Clean(out))
	}
	path, err := ensureSourceExt(lang, out)
	if err != nil {
		return err
	}
	rel, err := filepath.Rel(ws, path)
	if err != nil || strings.HasPrefix(rel, "..") {
		return fmt.Errorf("new 的目标路径必须位于工作区内: %s", ws)
	}
	if _, err := os.Stat(path); err == nil {
		return fmt.Errorf("文件已存在: %s", path)
	}
	if err := os.MkdirAll(filepath.Dir(path), 0o755); err != nil {
		return err
	}
	var body string
	switch lang {
	case LangCPP:
		body = cppTemplate
	case LangGo:
		body = goTemplate
	default:
		return NewUsageError("内部错误：未知语言")
	}
	if err := os.WriteFile(path, []byte(body), 0o644); err != nil {
		return err
	}
	inPath, outPath, err := EnsureIOCaseFiles(ws, path)
	if err != nil {
		return err
	}
	fmt.Println("已创建:", path)
	fmt.Println("已创建:", inPath)
	fmt.Println("已创建:", outPath)
	return nil
}

func ensureSourceExt(lang Lang, path string) (string, error) {
	ext := filepath.Ext(path)
	switch lang {
	case LangCPP:
		if ext == "" {
			path += ".cpp"
		} else if ext != ".cpp" && ext != ".cc" && ext != ".cxx" {
			return "", NewUsageError("C++ 源文件扩展名应为 .cpp/.cc/.cxx，得到 %q", ext)
		}
	case LangGo:
		if ext == "" {
			path += ".go"
		} else if ext != ".go" {
			return "", NewUsageError("Go 源文件扩展名应为 .go，得到 %q", ext)
		}
	default:
		return "", NewUsageError("内部错误：未知语言")
	}
	return filepath.Abs(path)
}

func normalizeSourcePath(lang Lang, file string) (string, error) {
	ext := filepath.Ext(file)
	switch lang {
	case LangCPP:
		if ext == "" {
			file = file + ".cpp"
		} else if ext != ".cpp" && ext != ".cc" && ext != ".cxx" {
			return "", NewUsageError("C++ 源文件扩展名应为 .cpp/.cc/.cxx，得到 %q", ext)
		}
	case LangGo:
		if ext == "" {
			file = file + ".go"
		} else if ext != ".go" {
			return "", NewUsageError("Go 源文件扩展名应为 .go，得到 %q", ext)
		}
	}
	if filepath.IsAbs(file) {
		return filepath.Abs(file)
	}
	wd, err := os.Getwd()
	if err != nil {
		return "", err
	}
	clean := filepath.Clean(file)
	if ws, werr := ResolveWorkspaceRoot(wd); werr == nil {
		cand := filepath.Join(ws, clean)
		if rel, rerr := filepath.Rel(ws, cand); rerr == nil && !strings.HasPrefix(rel, "..") {
			return filepath.Abs(cand)
		}
	}
	return filepath.Abs(filepath.Join(wd, clean))
}

func (rn *Runner) build(lang Lang, sourceAbs string) (string, error) {
	id := BuildDirID(sourceAbs)
	switch lang {
	case LangCPP:
		return rn.buildCPP(sourceAbs, id)
	case LangGo:
		return rn.buildGo(sourceAbs, id)
	default:
		return "", NewUsageError("内部错误：未知语言")
	}
}

func (rn *Runner) buildCPP(sourceAbs, id string) (string, error) {
	if hint := cppCompilerHint(rn.GXX); hint != "" {
		return "", fmt.Errorf("%s", hint)
	}
	workDir := filepath.Join(rn.WorkspaceRoot, BuildRootDirName, "cpp", id)
	if err := os.MkdirAll(workDir, 0o755); err != nil {
		return "", err
	}
	bin := filepath.Join(workDir, "a.out")
	args := []string{
		"-std=gnu++17",
		"-Wall",
		"-Wextra",
		"-O2",
		"-save-temps",
		"-o", bin,
		sourceAbs,
	}
	cmd := exec.Command(rn.GXX, args...)
	cmd.Dir = workDir
	cmd.Stdout = rn.Stdout
	cmd.Stderr = rn.Stderr
	if err := cmd.Run(); err != nil {
		return "", fmt.Errorf("C++ 编译失败: %w", err)
	}
	return bin, nil
}

func (rn *Runner) buildGo(sourceAbs, id string) (string, error) {
	workDir := filepath.Join(rn.WorkspaceRoot, BuildRootDirName, "go", id)
	if err := os.MkdirAll(workDir, 0o755); err != nil {
		return "", err
	}
	bin := filepath.Join(workDir, "run.bin")
	cmd := exec.Command("go", "build", "-o", bin, sourceAbs)
	cmd.Dir = rn.WorkspaceRoot
	cmd.Stdout = rn.Stdout
	cmd.Stderr = rn.Stderr
	cmd.Env = os.Environ()
	if err := cmd.Run(); err != nil {
		return "", fmt.Errorf("Go 编译失败: %w", err)
	}
	return bin, nil
}

func (rn *Runner) exec(bin, sourceAbs string, stdin io.Reader, stdout, stderr io.Writer) error {
	cmd := exec.Command(bin)
	cmd.Stdin = stdin
	cmd.Stdout = stdout
	cmd.Stderr = stderr
	cmd.Dir = filepath.Dir(sourceAbs)
	cmd.Env = os.Environ()
	if err := cmd.Run(); err != nil {
		return fmt.Errorf("运行失败: %w", err)
	}
	return nil
}
