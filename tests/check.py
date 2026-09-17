#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
一键评测脚本。

用法（在仓库根目录下执行）：

    python3 tests/check.py                # 跑全部题目，测 answers/ 里的参考答案
    python3 tests/check.py L01_1           # 只跑 L01_1 这一题
    python3 tests/check.py L01              # 跑 L01 开头的所有题
    python3 tests/check.py --dir practice  # 测你自己写的 practice/ 里的代码
    python3 tests/check.py --compile-only --dir practice
                                          # 只检查能不能编译通过（不比对输出）

工作原理：
    1. 编译 <dir>/<题目名>.c
    2. 如果有 tests/cases/<题目名>.in，就把它当作程序的输入喂进去
    3. 把程序输出和 tests/cases/<题目名>.out 逐行比对
    4. 打印 通过 / 失败，失败时指出第几行不一样

多组测试数据：除了 L05_2.in/.out，还可以加 L05_2.2.in/.out、L05_2.3.in/.out，
评测脚本会自动全部跑一遍，全对才算通过。

文件类题目（L14）额外支持两种约定：
  tests/cases/<题目名>.fixture/    运行前把这个目录里的文件复制到运行目录
                                   （比如 L14_2 需要的 in.txt）
  tests/cases/<题目名>.mustcreate  里面每行一个文件名，程序运行后这些文件必须存在，
                                   且内容要和标准输出一致

没有 .in / .out 的题目只会被"编译检查"，不算失败。
"""

import argparse
import difflib
import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CASES = os.path.join(ROOT, "tests", "cases")
CFLAGS = ["-std=c11", "-Wall", "-Wextra", "-g"]


def find_compiler():
    """找一个能用的 C 编译器。

    Windows 上通常只有 gcc（MinGW），macOS / Linux 上是 clang 或 gcc。
    按 clang 优先的顺序找一个存在的；一个都没有时给出人话提示，
    而不是让学习者对着一句 "No such file or directory" 发懵。
    """
    for name in ("clang", "gcc", "cc"):
        path = shutil.which(name)
        if path:
            return path, name
    return None, None


CLANG, COMPILER_NAME = find_compiler()

# 骨架里预留的变量/参数没被用到是正常的，评测时不因此报错
SKELETON_SILENCE = [
    "-Wno-unused-variable",
    "-Wno-unused-parameter",
    "-Wno-unused-but-set-variable",
]

GREEN = "\033[32m"
RED = "\033[31m"
YELLOW = "\033[33m"
DIM = "\033[2m"
BOLD = "\033[1m"
RESET = "\033[0m"


def colorize(text, color):
    if sys.stdout.isatty():
        return f"{color}{text}{RESET}"
    return text


def collect_tasks(pattern):
    """找出所有有 .c 文件的题目名。"""
    tasks = set()
    for folder in ("answers", "practice"):
        full = os.path.join(ROOT, folder)
        if not os.path.isdir(full):
            continue
        for fn in os.listdir(full):
            if fn.endswith(".c"):
                tasks.add(fn[:-2])
    tasks = sorted(tasks)
    if pattern:
        tasks = [t for t in tasks if t.startswith(pattern)]
    return tasks


def compile_source(path, out_path, silence=False):
    if CLANG is None:
        raise RuntimeError(
            "找不到 C 编译器。请先安装编译器再运行评测：\n"
            "  Windows：装 MinGW-w64（见 setup/B-Windows本机安装.md）\n"
            "  macOS  ：在终端执行 xcode-select --install（见 setup/C-macOS本机安装.md）\n"
            "  Linux  ：sudo apt install gcc（或你发行版对应的包管理器）"
        )
    cmd = [CLANG] + CFLAGS + (SKELETON_SILENCE if silence else []) + [path, "-o", out_path]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    return proc


def read_case(name, ext):
    path = os.path.join(CASES, name + ext)
    if os.path.exists(path):
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    return None


def load_cases(name):
    """收集某道题的所有测试数据。

    支持多组数据：L05_2.in/.out 是第一组，L05_2.2.in/.out 是第二组，
    L05_2.3.in/.out 是第三组……全部都要通过才算这道题通过。
    """
    if os.path.exists(os.path.join(CASES, name + ".in")) or os.path.exists(
        os.path.join(CASES, name + ".out")
    ):
        cases = [(read_case(name, ".in"), read_case(name, ".out"))]
    else:
        cases = []

    i = 2
    while True:
        suffix = f".{i}"
        if not (
            os.path.exists(os.path.join(CASES, name + suffix + ".in"))
            or os.path.exists(os.path.join(CASES, name + suffix + ".out"))
        ):
            break
        cases.append((read_case(name, suffix + ".in"), read_case(name, suffix + ".out")))
        i += 1

    return cases


def normalize(text):
    """去掉末尾空行，方便比对。"""
    return text.replace("\r\n", "\n").rstrip("\n")


def normalize_lines(text):
    """逐行去掉行末空白后再比对。

    行末多一个空格是最难用肉眼发现的错误之一（diff 里两行长得一样），
    而且绝大多数题目和在线判题系统都不在意它。所以按忽略行末空白来判定通过，
    但会单独提示，让学习者知道这件事。
    """
    lines = normalize(text).split("\n")
    return "\n".join(line.rstrip() for line in lines)


def strip_trailing_ws(text):
    return "\n".join(line.rstrip() for line in text.split("\n"))


def show_ws_diff(expected, got):
    """专门显示"行末多了空格"的差异：把行末空白画成 · 让你看见。"""
    exp_lines = normalize(expected).split("\n")
    got_lines = normalize(got).split("\n")

    for i, (e, g) in enumerate(zip(exp_lines, got_lines), start=1):
        if e != g:
            print(f"        {colorize(f'第 {i} 行：', DIM)}")
            print(f"          期望 {colorize(visible(e), DIM)}")
            print(f"          实际 {colorize(visible(g), RED)}   ← 行末多了 "
                  f"{len(g) - len(e.rstrip()) if len(g) > len(e) else len(g) - len(g.rstrip())} 个空格")


def visible(line):
    """把行末空白显示成 · 方便肉眼看清。"""
    stripped = line.rstrip()
    trail = len(line) - len(stripped)
    return repr(stripped)[1:-1] + ("·" * trail)


def run_program(exe, stdin_text, cwd):
    """在指定目录里运行程序（这样 fopen 的相对路径会落在这里）。"""
    return subprocess.run(
        [exe],
        input=stdin_text,
        capture_output=True,
        text=True,
        timeout=10,
        cwd=cwd,
    )


def check_created_files(cwd, must_create, stdout):
    """检查程序有没有按要求生成文件，内容是否和屏幕输出一致。

    返回 (是否通过, 说明)。
    """
    for fn in must_create:
        path = os.path.join(cwd, fn)
        if not os.path.exists(path):
            return False, (
                f"没有生成文件 {fn}\n"
                f"提示：检查 fopen(\"{fn}\", \"w\") 是否成功、fclose 有没有忘"
            )
        with open(path, encoding="utf-8", errors="replace") as f:
            content = f.read()
        if normalize(content) != normalize(stdout):
            return False, (
                f"文件 {fn} 的内容和屏幕输出不一致\n"
                f"--- 文件内容 ---\n{normalize(content)}\n"
                f"--- 屏幕输出 ---\n{normalize(stdout)}"
            )
    return True, ""


def show_diff(expected, got):
    exp_lines = normalize(expected).split("\n")
    got_lines = normalize(got).split("\n")
    diff = list(
        difflib.unified_diff(
            exp_lines, got_lines, fromfile="期望输出", tofile="你的输出", lineterm=""
        )
    )
    for line in diff[:40]:
        if line.startswith("+") and not line.startswith("+++"):
            print("      " + colorize(line, GREEN))
        elif line.startswith("-") and not line.startswith("---"):
            print("      " + colorize(line, RED))
        else:
            print("      " + colorize(line, DIM))
    if len(diff) > 40:
        print("      " + colorize("... (差异过长，已截断)", DIM))


def run_one(name, source_dir, compile_only=False):
    src = os.path.join(ROOT, source_dir, name + ".c")
    if not os.path.exists(src):
        return "missing", f"{source_dir}/{name}.c 不存在"

    with open(src, encoding="utf-8") as f:
        head = f.read(600)

    # 找错题骨架故意包含错误，编译不过才是正常的，跳过编译检查
    if "@NOCOMPILE" in head:
        return "noc", ""

    with tempfile.TemporaryDirectory() as tmp:
        # Windows 上编译器产出的可执行文件带 .exe 后缀
        exe = os.path.join(tmp, name + (".exe" if os.name == "nt" else ""))

        proc = compile_source(src, exe, silence=True)
        if proc.returncode != 0:
            # 编译失败时，去掉"屏蔽骨架警告"再跑一次，好看到真实问题
            proc2 = compile_source(src, exe, silence=False)
            msg = (proc2.stderr or proc2.stdout).strip()
            return "compile_error", msg

        warnings = ""
        if proc.stderr.strip():
            warnings = proc.stderr.strip()

        if compile_only:
            return ("warn" if warnings else "ok"), warnings

        # 文件类题目：把 fixture 目录里的文件复制进运行目录
        fixture = os.path.join(CASES, name + ".fixture")
        if os.path.isdir(fixture):
            for fn in os.listdir(fixture):
                shutil.copy(os.path.join(fixture, fn), os.path.join(tmp, fn))

        must_create = []
        mc_path = os.path.join(CASES, name + ".mustcreate")
        if os.path.exists(mc_path):
            with open(mc_path, encoding="utf-8") as f:
                must_create = [ln.strip() for ln in f if ln.strip()]

        cases = load_cases(name)

        if not cases:
            try:
                run = run_program(exe, "", tmp)
            except subprocess.TimeoutExpired:
                return "timeout", "程序运行超过 10 秒，很可能是死循环（检查 while/for 的退出条件）"
            if run.returncode != 0:
                return (
                    "runtime_error",
                    f"程序异常退出（返回码 {run.returncode}）\n{run.stderr.strip()}",
                )
            ok, detail = check_created_files(tmp, must_create, run.stdout)
            if not ok:
                return "file_wrong", detail, run.stdout, "", None
            return "no_case", normalize(run.stdout)

        for idx, (stdin_text, expected) in enumerate(cases, start=1):
            label = "" if len(cases) == 1 else f"第 {idx} 组数据"

            # 每组数据前把 fixture 重新复制一遍，并清掉上一轮生成的文件
            for fn in must_create:
                p = os.path.join(tmp, fn)
                if os.path.exists(p):
                    os.remove(p)
            if os.path.isdir(fixture):
                for fn in os.listdir(fixture):
                    shutil.copy(os.path.join(fixture, fn), os.path.join(tmp, fn))

            try:
                run = run_program(exe, stdin_text if stdin_text is not None else "", tmp)
            except subprocess.TimeoutExpired:
                return (
                    "timeout",
                    f"{label}：程序运行超过 10 秒，很可能是死循环（检查 while/for 的退出条件）",
                )

            if run.returncode != 0:
                return (
                    "runtime_error",
                    f"{label}：程序异常退出（返回码 {run.returncode}）\n{run.stderr.strip()}",
                )

            ok, detail = check_created_files(tmp, must_create, run.stdout)
            if not ok:
                return "file_wrong", detail, run.stdout, label, stdin_text

            if expected is None:
                continue

            if normalize(run.stdout) != normalize(expected):
                if normalize_lines(run.stdout) == normalize_lines(expected):
                    # 只有行末空白不同：算通过，但提醒一下
                    return "ws_warn", strip_trailing_ws(run.stdout), expected, label, stdin_text
                return "wrong", run.stdout, expected, label, stdin_text

        return ("warn" if warnings else "ok"), warnings


def main():
    parser = argparse.ArgumentParser(description="C 语言练习一键评测")
    parser.add_argument("pattern", nargs="?", default=None, help="题目名前缀，如 L01_1 或 L01")
    parser.add_argument(
        "--dir",
        default="practice",
        choices=["practice", "answers"],
        help="要评测哪个目录（默认 practice，即你自己写的）",
    )
    parser.add_argument("--compile-only", action="store_true", help="只检查能否编译")
    args = parser.parse_args()

    tasks = collect_tasks(args.pattern)
    if not tasks:
        print(f"没有找到匹配 {args.pattern!r} 的题目。")
        return 1

    n_ok = n_warn = n_fail = n_skip = n_wswarn = 0
    failures = []

    print()
    print(colorize(f"评测目录：{args.dir}/", BOLD) + f"    共 {len(tasks)} 题")
    print()

    for name in tasks:
        result = run_one(name, args.dir, compile_only=args.compile_only)

        if result[0] == "ok":
            n_ok += 1
            print(f"  {colorize('通过', GREEN)}  {name}")
        elif result[0] == "warn":
            n_warn += 1
            print(f"  {colorize('通过', GREEN)}  {name}  {colorize('(有警告)', YELLOW)}")
            for line in result[1].splitlines():
                print(f"        {colorize(line, DIM)}")
        elif result[0] == "no_case":
            n_skip += 1
            print(f"  {colorize('跳过', DIM)}  {name}  {colorize('(无期望输出，仅编译检查)', DIM)}")
        elif result[0] == "noc":
            n_skip += 1
            print(f"  {colorize('跳过', DIM)}  {name}  {colorize('(找错题，骨架自带错误)', DIM)}")
        elif result[0] == "compile_error":
            n_fail += 1
            failures.append(name)
            print(f"  {colorize('编译失败', RED)}  {name}")
            for line in result[1].splitlines()[:12]:
                print(f"        {colorize(line, RED)}")
        elif result[0] == "file_wrong":
            n_fail += 1
            failures.append(name)
            label = result[3] if len(result) > 3 else ""
            print(f"  {colorize('文件不对', RED)}  {name}" + (f"  {colorize(label, YELLOW)}" if label else ""))
            for line in result[1].splitlines()[:14]:
                print(f"        {colorize(line, RED)}")
        elif result[0] == "ws_warn":
            n_ok += 1
            n_wswarn += 1
            print(f"  {colorize('通过', GREEN)}  {name}  {colorize('(行末多了空格)', YELLOW)}")
            show_ws_diff(result[1], result[2])
        elif result[0] == "wrong":
            n_fail += 1
            failures.append(name)
            label = result[3] if len(result) > 3 else ""
            stdin_text = result[4] if len(result) > 4 else None
            print(f"  {colorize('输出不对', RED)}  {name}" + (f"  {colorize(label, YELLOW)}" if label else ""))
            if stdin_text is not None:
                show_input = normalize(stdin_text).replace("\n", " / ")
                print(f"        {colorize('输入：' + show_input, DIM)}")
            show_diff(result[2], result[1])
        elif result[0] == "timeout":
            n_fail += 1
            failures.append(name)
            print(f"  {colorize('超时', RED)}  {name}")
            print(f"        {colorize(result[1], RED)}")
        elif result[0] == "runtime_error":
            n_fail += 1
            failures.append(name)
            print(f"  {colorize('运行出错', RED)}  {name}")
            for line in result[1].splitlines()[:8]:
                print(f"        {colorize(line, RED)}")
        elif result[0] == "missing":
            n_fail += 1
            failures.append(name)
            print(f"  {colorize('缺文件', RED)}  {name}")

    print()
    summary = f"通过 {n_ok}"
    if n_warn:
        summary += f" / 有警告 {n_warn}"
    if n_wswarn:
        summary += f" / 行末空格 {n_wswarn}"
    if n_skip:
        summary += f" / 仅编译 {n_skip}"
    if n_fail:
        summary += f" / 失败 {n_fail}"
    color = GREEN if n_fail == 0 else RED
    print(colorize(f"结果：{summary}", color))
    if failures:
        print(colorize("失败的题目：" + "、".join(failures), RED))
    print()

    return 1 if n_fail else 0


if __name__ == "__main__":
    sys.exit(main())
