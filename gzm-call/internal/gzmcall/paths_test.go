package gzmcall

import (
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestFindWorkspaceRoot_directIOCases(t *testing.T) {
	t.Parallel()
	root := t.TempDir()
	require.NoError(t, os.MkdirAll(filepath.Join(root, IOCasesDirName), 0o755))
	sub := filepath.Join(root, "a", "b")
	require.NoError(t, os.MkdirAll(sub, 0o755))

	got, err := FindWorkspaceRoot(sub)
	require.NoError(t, err)
	require.Equal(t, root, got)
}

func TestFindWorkspaceRoot_nestedWorkspace(t *testing.T) {
	t.Parallel()
	root := t.TempDir()
	ws := filepath.Join(root, "repo", DefaultWorkspaceDirName)
	require.NoError(t, os.MkdirAll(filepath.Join(ws, IOCasesDirName), 0o755))
	cwd := filepath.Join(root, "repo", "other")
	require.NoError(t, os.MkdirAll(cwd, 0o755))

	got, err := FindWorkspaceRoot(cwd)
	require.NoError(t, err)
	require.Equal(t, ws, got)
}

func TestCasePaths(t *testing.T) {
	t.Parallel()
	root := t.TempDir()
	src := filepath.Join(root, "p", "q", "main.cpp")
	inPath, outPath, err := CasePaths(root, src)
	require.NoError(t, err)
	require.Equal(t, filepath.Join(root, IOCasesDirName, "p", "q", "main.in"), inPath)
	require.Equal(t, filepath.Join(root, IOCasesDirName, "p", "q", "main.out"), outPath)
}

func TestCasePaths_rejectOutsideWorkspace(t *testing.T) {
	t.Parallel()
	root := t.TempDir()
	outside := filepath.Join(t.TempDir(), "x.go")
	_, _, err := CasePaths(root, outside)
	require.Error(t, err)
}

func TestEnsureIOCaseFiles_createsEmptyCases(t *testing.T) {
	t.Parallel()
	root := t.TempDir()
	require.NoError(t, os.MkdirAll(filepath.Join(root, IOCasesDirName), 0o755))
	src := filepath.Join(root, "foo.cpp")
	require.NoError(t, os.WriteFile(src, []byte("int main(){}"), 0o644))

	inPath, outPath, err := EnsureIOCaseFiles(root, src)
	require.NoError(t, err)
	require.FileExists(t, inPath)
	require.FileExists(t, outPath)
	require.Equal(t, filepath.Join(root, IOCasesDirName, "foo.in"), inPath)
	require.Equal(t, filepath.Join(root, IOCasesDirName, "foo.out"), outPath)

	inData, err := os.ReadFile(inPath)
	require.NoError(t, err)
	require.Empty(t, inData)
}
