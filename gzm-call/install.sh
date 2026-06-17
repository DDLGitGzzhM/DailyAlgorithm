#!/usr/bin/env bash
# 安装 gzm-call 并将 Go bin 目录加入 shell PATH（幂等，可重复运行）。
set -euo pipefail

MARKER="# >>> gzm-call >>>"
MARKER_END="# <<< gzm-call <<<"
PREFERRED_GXX_NAMES=(g++-7 g++-9 g++-10 g++-11 g++-12 g++-13 g++-14 g++-15)

log() { printf '%s\n' "$*"; }
err() { printf '错误: %s\n' "$*" >&2; }

if ! command -v go >/dev/null 2>&1; then
	err "未找到 Go，请先安装: https://go.dev/dl/"
	exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

log "正在编译安装 gzm-call ..."
(
	cd "$SCRIPT_DIR"
	go install ./cmd/gzm-call/
)

GOBIN="$(go env GOBIN)"
GOPATH="$(go env GOPATH)"
if [[ -n "$GOBIN" ]]; then
	BIN_DIR="$GOBIN"
else
	BIN_DIR="$GOPATH/bin"
fi

if [[ ! -x "$BIN_DIR/gzm-call" ]]; then
	err "安装失败：未找到 $BIN_DIR/gzm-call"
	exit 1
fi

log "已安装: $BIN_DIR/gzm-call"

gcc_bin_dirs() {
	local prefix formula
	for prefix in /opt/homebrew/opt /usr/local/opt; do
		[[ -d "$prefix" ]] || continue
		for formula in gcc@7 gcc@9 gcc gcc@11 gcc@12 gcc@13 gcc@14 gcc@15; do
			if [[ -d "$prefix/$formula/bin" ]]; then
				echo "$prefix/$formula/bin"
			fi
		done
	done
}

is_gnu_gxx() {
	local compiler="$1"
	[[ -x "$compiler" ]] || return 1
	"$compiler" --version 2>/dev/null | grep -Eqi 'gcc|g\+\+' || return 1
	"$compiler" --version 2>/dev/null | grep -qi clang && return 1
	local major
	major="$("$compiler" -dumpversion 2>/dev/null | cut -d. -f1)"
	[[ -n "$major" && "$major" -ge 7 ]]
}

find_gnu_gxx() {
	local name dir gcc_dir
	for gcc_dir in $(gcc_bin_dirs); do
		for name in "${PREFERRED_GXX_NAMES[@]}"; do
			if [[ -x "$gcc_dir/$name" ]] && is_gnu_gxx "$gcc_dir/$name"; then
				echo "$gcc_dir/$name"
				return 0
			fi
		done
	done
	for name in "${PREFERRED_GXX_NAMES[@]}" g++; do
		if command -v "$name" >/dev/null 2>&1 && is_gnu_gxx "$(command -v "$name")"; then
			command -v "$name"
			return 0
		fi
	done
	for dir in /opt/homebrew/bin /usr/local/bin; do
		for name in "${PREFERRED_GXX_NAMES[@]}"; do
			if [[ -x "$dir/$name" ]] && is_gnu_gxx "$dir/$name"; then
				echo "$dir/$name"
				return 0
			fi
		done
	done
	return 1
}

setup_gnu_gxx() {
	if find_gnu_gxx >/dev/null 2>&1; then
		return 0
	fi
	if [[ "$(uname -s)" != "Darwin" ]]; then
		return 1
	fi
	if ! command -v brew >/dev/null 2>&1; then
		return 1
	fi
	log "未检测到 GNU G++，正在通过 Homebrew 安装 gcc（G++ 7.3.0+，支持 bits/stdc++.h）..."
	brew install gcc
}

detect_rc_file() {
	local shell_name="${SHELL:-}"
	case "$shell_name" in
	*/zsh)
		echo "$HOME/.zshrc"
		;;
	*/bash)
		if [[ -f "$HOME/.bashrc" ]]; then
			echo "$HOME/.bashrc"
		else
			echo "$HOME/.bash_profile"
		fi
		;;
	*)
		if [[ -f "$HOME/.zshrc" ]]; then
			echo "$HOME/.zshrc"
		elif [[ -f "$HOME/.bashrc" ]]; then
			echo "$HOME/.bashrc"
		elif [[ -f "$HOME/.bash_profile" ]]; then
			echo "$HOME/.bash_profile"
		else
			echo "$HOME/.profile"
		fi
		;;
	esac
}

write_shell_config() {
	local rc_file="$1"
	local gxx="${2:-}"
	local gxx_bin_dir=""
	if [[ -n "$gxx" ]]; then
		gxx_bin_dir="$(dirname "$gxx")"
	fi

	if grep -Fq "$MARKER" "$rc_file" 2>/dev/null; then
		log "shell 配置已存在，跳过写入: $rc_file"
		if [[ -n "$gxx" ]] && ! grep -Fq 'GZM_CALL_GXX=' "$rc_file" 2>/dev/null; then
			log "追加 GZM_CALL_GXX 到: $rc_file"
			sed -i.bak "/^${MARKER}$/a\\
export GZM_CALL_GXX=\"${gxx}\"
" "$rc_file"
			rm -f "${rc_file}.bak"
		fi
		if [[ -n "$gxx_bin_dir" ]] && ! grep -Fq "$gxx_bin_dir" "$rc_file" 2>/dev/null; then
			log "追加 GNU G++ PATH 到: $rc_file"
			sed -i.bak "/^${MARKER}$/a\\
export PATH=\"${gxx_bin_dir}:\$PATH\"
" "$rc_file"
			rm -f "${rc_file}.bak"
		fi
		return 0
	fi

	log "写入 shell 配置到: $rc_file"
	{
		echo ""
		echo "$MARKER"
		echo "# 由 gzm-call/install.sh 自动添加"
		printf 'export PATH="$PATH:%s"\n' "$BIN_DIR"
		if [[ -n "$gxx_bin_dir" ]]; then
			printf 'export PATH="%s:$PATH"\n' "$gxx_bin_dir"
		fi
		if [[ -n "$gxx" ]]; then
			printf 'export GZM_CALL_GXX="%s"\n' "$gxx"
		fi
		echo "$MARKER_END"
	} >>"$rc_file"
}

GXX=""
if setup_gnu_gxx; then
	:
fi
if GXX="$(find_gnu_gxx)"; then
	log "检测到 GNU G++: $GXX"
	export GZM_CALL_GXX="$GXX"
	export PATH="$(dirname "$GXX"):$PATH"
else
	log "警告: 未找到 GNU G++，C++ 模板中的 bits/stdc++.h 可能无法编译。"
	log "macOS 可执行: brew install gcc，然后重新运行本脚本。"
fi

RC_FILE="$(detect_rc_file)"
touch "$RC_FILE"
write_shell_config "$RC_FILE" "$GXX"

export PATH="$PATH:$BIN_DIR"

if command -v gzm-call >/dev/null 2>&1; then
	log ""
	log "安装成功。当前 shell 已可直接使用 gzm-call。"
	log "示例: gzm-call cpp run test.cpp"
else
	log ""
	log "安装完成，但当前 shell 仍未识别 gzm-call。"
	log "请执行: source \"$RC_FILE\""
	log "或重新打开终端后再试。"
fi
