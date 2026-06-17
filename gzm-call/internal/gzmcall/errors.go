package gzmcall

import "fmt"

// UsageError 表示命令行参数或用法错误。
type UsageError struct {
	Msg string
}

func (e *UsageError) Error() string {
	return e.Msg
}

// NewUsageError 构造用法错误。
func NewUsageError(format string, args ...any) error {
	return &UsageError{Msg: fmt.Sprintf(format, args...)}
}
