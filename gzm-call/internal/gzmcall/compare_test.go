package gzmcall

import (
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestCompareOutputs_ok(t *testing.T) {
	t.Parallel()
	dir := t.TempDir()
	path := filepath.Join(dir, "exp.out")
	require.NoError(t, os.WriteFile(path, []byte("1 2 3\n"), 0o644))
	require.NoError(t, CompareOutputs([]byte("1 2 3\n\n"), path))
}

func TestCompareOutputs_mismatch(t *testing.T) {
	t.Parallel()
	dir := t.TempDir()
	path := filepath.Join(dir, "exp.out")
	require.NoError(t, os.WriteFile(path, []byte("ok\n"), 0o644))
	require.Error(t, CompareOutputs([]byte("no\n"), path))
}
