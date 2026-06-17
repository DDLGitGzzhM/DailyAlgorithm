package gzmcall

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

const (
	// IOCasesDirName 为存放 .in / .out 的目录名（位于工作区根下）。
	IOCasesDirName = "io_cases"
	// BuildRootDirName 为编译产物根目录（相对工作区根）。
	BuildRootDirName = ".gzm-call-build"
	// DefaultWorkspaceDirName 为在仓库内默认的用户工作区目录名。
	DefaultWorkspaceDirName = "workspace"
)

func hasIOCases(dir string) bool {
	st, err := os.Stat(filepath.Join(dir, IOCasesDirName))
	return err == nil && st.IsDir()
}

func firstNonEmpty(a, b string) string {
	if strings.TrimSpace(a) != "" {
		return strings.TrimSpace(a)
	}
	return strings.TrimSpace(b)
}

// FindWorkspaceRoot 从 seed 路径向上查找包含 io_cases 的工作区根；若未找到则尝试
// <祖先>/workspace/io_cases 约定（便于从仓库根运行命令）。
func FindWorkspaceRoot(seed string) (string, error) {
	start, err := filepath.Abs(seed)
	if err != nil {
		return "", fmt.Errorf("解析路径: %w", err)
	}
	if st, err := os.Stat(start); err == nil && !st.IsDir() {
		start = filepath.Dir(start)
	}
	for dir := start; ; dir = filepath.Dir(dir) {
		if hasIOCases(dir) {
			return dir, nil
		}
		parent := filepath.Dir(dir)
		if parent == dir {
			break
		}
	}
	for dir := start; ; dir = filepath.Dir(dir) {
		nested := filepath.Join(dir, DefaultWorkspaceDirName, IOCasesDirName)
		if st, err := os.Stat(nested); err == nil && st.IsDir() {
			return filepath.Join(dir, DefaultWorkspaceDirName), nil
		}
		parent := filepath.Dir(dir)
		if parent == dir {
			break
		}
	}
	return "", fmt.Errorf(
		"未找到工作区：请确保存在 %s 目录，或设置 GZM_CALL_WORKSPACE",
		IOCasesDirName,
	)
}

// ResolveWorkspaceRoot 优先使用 GZM_CALL_WORKSPACE / GZM_CALL_ROOT，否则调用 FindWorkspaceRoot。
func ResolveWorkspaceRoot(startDir string) (string, error) {
	if v := firstNonEmpty(os.Getenv("GZM_CALL_WORKSPACE"), os.Getenv("GZM_CALL_ROOT")); v != "" {
		abs, err := filepath.Abs(v)
		if err != nil {
			return "", err
		}
		if err := os.MkdirAll(filepath.Join(abs, IOCasesDirName), 0o755); err != nil {
			return "", err
		}
		return abs, nil
	}
	return FindWorkspaceRoot(startDir)
}

// ResolveOrCreateWorkspace 解析工作区；若找不到则创建 <cwd>/workspace 并初始化目录结构。
func ResolveOrCreateWorkspace(cwd string) (string, error) {
	ws, err := ResolveWorkspaceRoot(cwd)
	if err == nil {
		return ws, EnsureWorkspaceLayout(ws)
	}
	fallback := filepath.Join(cwd, DefaultWorkspaceDirName)
	if err := os.MkdirAll(filepath.Join(fallback, IOCasesDirName), 0o755); err != nil {
		return "", err
	}
	return fallback, EnsureWorkspaceLayout(fallback)
}

// EnsureWorkspaceLayout 确保工作区存在 io_cases 与最小 go.mod（便于 go build）。
func EnsureWorkspaceLayout(ws string) error {
	if err := os.MkdirAll(filepath.Join(ws, IOCasesDirName), 0o755); err != nil {
		return err
	}
	gm := filepath.Join(ws, "go.mod")
	if _, err := os.Stat(gm); os.IsNotExist(err) {
		body := []byte("module userworkspace\n\ngo 1.21\n")
		if err := os.WriteFile(gm, body, 0o644); err != nil {
			return err
		}
	}
	return nil
}

// CasePaths 根据工作区根与源码绝对路径，返回对应的 .in / .out 路径。
func CasePaths(workspaceRoot, sourceAbs string) (inPath, outPath string, err error) {
	root, err := filepath.Abs(workspaceRoot)
	if err != nil {
		return "", "", err
	}
	src, err := filepath.Abs(sourceAbs)
	if err != nil {
		return "", "", err
	}
	rel, err := filepath.Rel(root, src)
	if err != nil {
		return "", "", err
	}
	if strings.HasPrefix(rel, "..") {
		return "", "", fmt.Errorf("源码不在工作区根之下: %s", src)
	}
	base := strings.TrimSuffix(rel, filepath.Ext(rel))
	inPath = filepath.Join(root, IOCasesDirName, base+".in")
	outPath = filepath.Join(root, IOCasesDirName, base+".out")
	return inPath, outPath, nil
}

// EnsureIOCaseFiles 创建与源码对应的空 .in / .out（已存在则跳过）。
func EnsureIOCaseFiles(workspaceRoot, sourceAbs string) (inPath, outPath string, err error) {
	inPath, outPath, err = CasePaths(workspaceRoot, sourceAbs)
	if err != nil {
		return "", "", err
	}
	if err := os.MkdirAll(filepath.Dir(inPath), 0o755); err != nil {
		return "", "", err
	}
	for _, p := range []string{inPath, outPath} {
		if _, err := os.Stat(p); err == nil {
			continue
		} else if !os.IsNotExist(err) {
			return "", "", err
		}
		if err := os.WriteFile(p, nil, 0o644); err != nil {
			return "", "", err
		}
	}
	return inPath, outPath, nil
}

// BuildDirID 返回用于构建目录的稳定短 ID（基于源码绝对路径）。
func BuildDirID(sourceAbs string) string {
	sum := sha256.Sum256([]byte(sourceAbs))
	return hex.EncodeToString(sum[:8])
}

// SanitizeBuildFileName 将路径转为适合作为构建产物的文件名片段。
func SanitizeBuildFileName(sourceAbs string) string {
	base := filepath.Base(sourceAbs)
	ext := filepath.Ext(base)
	name := strings.TrimSuffix(base, ext)
	if name == "" {
		name = "a"
	}
	return name
}
