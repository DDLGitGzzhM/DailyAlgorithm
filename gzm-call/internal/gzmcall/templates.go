package gzmcall

const cppTemplate = `#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 使用 gzm-call cpp check <本文件> 时会自动从 io_cases 读入 .in 并比对 .out。
	// 本地自测可取消注释并调整路径（相对源文件所在目录运行时，常用 io_cases/...）：
	// freopen("io_cases/example.in", "r", stdin);
	// freopen("io_cases/example.out", "w", stdout);

	return 0;
}
`

const goTemplate = `package main

import (
	"bufio"
	"os"
)

func main() {
	// 注意：以 '_' 或 '.' 开头的 .go 文件名可能被 go build 忽略，尽量避免。
	// 使用 gzm-call go check <本文件> 时会自动从 io_cases 读入 .in 并比对 .out。
	// 本地自测可取消注释并调整路径：
	// in, err := os.Open("io_cases/example.in")
	// if err != nil {
	// 	panic(err)
	// }
	// defer in.Close()
	// os.Stdin = in

	_ = bufio.NewReader(os.Stdin)
}
`
