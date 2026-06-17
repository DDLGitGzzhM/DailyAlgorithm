package gzmcall

import (
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestResolveGXX_respectsEnv(t *testing.T) {
	t.Setenv("GZM_CALL_GXX", "/custom/g++-7")
	require.Equal(t, "/custom/g++-7", ResolveGXX())
}

func TestDefaultGXXName(t *testing.T) {
	t.Parallel()
	require.Equal(t, "g++-7", DefaultGXXName)
}

func TestCppCompilerHint_nonGNU(t *testing.T) {
	t.Parallel()
	hint := cppCompilerHint("/usr/bin/g++")
	if isGNUCompiler("/usr/bin/g++") {
		require.Empty(t, hint)
		return
	}
	require.Contains(t, hint, "gnu++17")
	require.Contains(t, hint, "brew install gcc")
}

func TestFindGNUCompiler_missing(t *testing.T) {
	t.Parallel()
	_, ok := findGNUCompiler("g++-not-exist-999")
	require.False(t, ok)
}

func TestIsExecutable(t *testing.T) {
	t.Parallel()
	dir := t.TempDir()
	file := filepath.Join(dir, "tool")
	require.NoError(t, os.WriteFile(file, []byte("x"), 0o755))
	require.True(t, isExecutable(file))
	require.NoError(t, os.Chmod(file, 0o644))
	require.False(t, isExecutable(file))
}
