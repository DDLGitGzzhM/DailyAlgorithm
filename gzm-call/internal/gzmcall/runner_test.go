package gzmcall

import (
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestParseLang(t *testing.T) {
	t.Parallel()
	for _, tc := range []struct {
		in   string
		want Lang
	}{
		{"cpp", LangCPP},
		{"C++", LangCPP},
		{"go", LangGo},
	} {
		got, err := ParseLang(tc.in)
		require.NoError(t, err)
		require.Equal(t, tc.want, got)
	}
	_, err := ParseLang("rust")
	require.Error(t, err)
}

func TestNormalizeSourcePath(t *testing.T) {
	t.Parallel()
	p, err := normalizeSourcePath(LangCPP, "abc")
	require.NoError(t, err)
	require.Equal(t, "abc.cpp", filepath.Base(p))
}

func TestNormalizeSourcePath_prefersWorkspace(t *testing.T) {
	root := t.TempDir()
	ws := filepath.Join(root, "workspace")
	require.NoError(t, os.MkdirAll(filepath.Join(ws, IOCasesDirName), 0o755))
	repo := filepath.Join(root, "repo")
	require.NoError(t, os.MkdirAll(repo, 0o755))

	oldWd, err := os.Getwd()
	require.NoError(t, err)
	t.Cleanup(func() { _ = os.Chdir(oldWd) })
	require.NoError(t, os.Chdir(repo))

	p, err := normalizeSourcePath(LangCPP, "a")
	require.NoError(t, err)
	require.Equal(t, "a.cpp", filepath.Base(p))
	require.Equal(t, filepath.Base(ws), filepath.Base(filepath.Dir(p)))
}
