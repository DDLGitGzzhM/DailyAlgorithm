package main

import (
	"errors"
	"fmt"
	"os"

	"DailyAlgorithm/gzm-call/internal/gzmcall"
)

func main() {
	if err := gzmcall.RunCLI(os.Args[1:]); err != nil {
		var usage *gzmcall.UsageError
		if errors.As(err, &usage) {
			fmt.Fprintln(os.Stderr, usage.Error())
			os.Exit(2)
		}
		fmt.Fprintln(os.Stderr, "错误:", err)
		os.Exit(1)
	}
}
