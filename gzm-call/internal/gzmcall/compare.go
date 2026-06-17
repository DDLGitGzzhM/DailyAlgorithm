package gzmcall

import (
	"bytes"
	"fmt"
	"os"
)

// CompareOutputs 将实际输出与期望文件内容比对（去掉末尾连续换行后比较）。
func CompareOutputs(actual []byte, expectedPath string) error {
	want, err := os.ReadFile(expectedPath)
	if err != nil {
		return fmt.Errorf("读取期望输出: %w", err)
	}
	a := trimTrailingNewlines(actual)
	b := trimTrailingNewlines(want)
	if bytes.Equal(a, b) {
		return nil
	}
	return fmt.Errorf("输出与 %s 不一致", expectedPath)
}

func trimTrailingNewlines(b []byte) []byte {
	return bytes.TrimRight(b, "\n\r")
}
