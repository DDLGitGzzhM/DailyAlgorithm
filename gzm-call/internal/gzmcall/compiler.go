package gzmcall

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strconv"
	"strings"
)

const (
	// DefaultGXXName 为首选 C++ 编译器命令（GNU G++ 7.x，目标 7.3.0）。
	DefaultGXXName = "g++-7"
	// RequiredGXXMajor 为可接受的最低 GCC 主版本号。
	RequiredGXXMajor = 7
)

// preferredGXXNames 按优先级排列；macOS Homebrew 通常无 g++-7，会落到 g++-14 等。
var preferredGXXNames = []string{
	"g++-7", "g++-9", "g++-10", "g++-11", "g++-12", "g++-13", "g++-14", "g++-15",
}

var gnuGXXSearchDirs = []string{
	"/opt/homebrew/opt/gcc@7/bin",
	"/usr/local/opt/gcc@7/bin",
	"/opt/homebrew/opt/gcc@9/bin",
	"/usr/local/opt/gcc@9/bin",
	"/opt/homebrew/opt/gcc/bin",
	"/usr/local/opt/gcc/bin",
	"/opt/homebrew/bin",
	"/usr/local/bin",
}

// ResolveGXX 返回 C++ 编译器路径。优先 GZM_CALL_GXX，其次 GNU g++（>=7，支持 bits/stdc++.h）。
func ResolveGXX() string {
	if v := strings.TrimSpace(os.Getenv("GZM_CALL_GXX")); v != "" {
		return v
	}
	if p, ok := findPreferredGNUCompiler(); ok {
		return p
	}
	return DefaultGXXName
}

func findPreferredGNUCompiler() (string, bool) {
	for _, name := range preferredGXXNames {
		if p, ok := findGNUCompiler(name); ok && isGCCMajorAtLeast(p, RequiredGXXMajor) {
			return p, true
		}
	}
	if p, ok := findGNUCompiler("g++"); ok && isGCCMajorAtLeast(p, RequiredGXXMajor) {
		return p, true
	}
	return "", false
}

func findGNUCompiler(name string) (string, bool) {
	if p, err := exec.LookPath(name); err == nil && isGNUCompiler(p) {
		return p, true
	}
	for _, dir := range gnuGXXSearchDirs {
		p := filepath.Join(dir, name)
		if isExecutable(p) && isGNUCompiler(p) {
			return p, true
		}
	}
	return "", false
}

func isExecutable(path string) bool {
	st, err := os.Stat(path)
	return err == nil && !st.IsDir() && st.Mode()&0o111 != 0
}

func isGNUCompiler(path string) bool {
	out, err := exec.Command(path, "--version").Output()
	if err != nil {
		return false
	}
	lower := strings.ToLower(string(out))
	if strings.Contains(lower, "clang") {
		return false
	}
	return strings.Contains(lower, "gcc") || strings.Contains(lower, "g++")
}

func isGCCMajorAtLeast(path string, major int) bool {
	out, err := exec.Command(path, "-dumpversion").Output()
	if err != nil {
		return false
	}
	v := strings.TrimSpace(string(out))
	parts := strings.Split(v, ".")
	if len(parts) == 0 {
		return false
	}
	got, err := strconv.Atoi(parts[0])
	return err == nil && got >= major
}

func cppCompilerHint(gxx string) string {
	if isGNUCompiler(gxx) && isGCCMajorAtLeast(gxx, RequiredGXXMajor) {
		return ""
	}
	return fmt.Sprintf(
		"当前 C++ 编译器 %q 不可用，需要 GNU G++ %d.3.0 及以上（-std=gnu++17）。\n"+
			"macOS 请执行: brew install gcc\n"+
			"然后重新运行 gzm-call/install.sh，或手动设置 GZM_CALL_GXX（如 g++-14）。",
		gxx,
		RequiredGXXMajor,
	)
}
