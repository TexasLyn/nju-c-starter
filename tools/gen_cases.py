#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""辅助工具：编译 answers/<name>.c 并用指定的输入生成 .out 期望文件。

用法（在仓库根目录执行）：python3 tools/gen_cases.py <题目名> <输入文件1> ...

不是课程材料的一部分，只是维护 tests/cases/ 时用的辅助脚本。
"""

import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CASES = os.path.join(ROOT, "tests", "cases")


def find_compiler():
    """按 clang → gcc → cc 的顺序找编译器，兼容 Windows 上只有 gcc 的情况。"""
    for name in ("clang", "gcc", "cc"):
        path = shutil.which(name)
        if path:
            return path
    return None


CLANG = find_compiler()


def main():
    if CLANG is None:
        print("找不到 C 编译器（需要 clang 或 gcc），请先看 setup/ 里的安装教程。")
        return 1

    if len(sys.argv) < 3:
        print("用法：python3 tools/gen_cases.py <题目名> <输入文件1> [<输入文件2> ...]")
        return 1

    name = sys.argv[1]
    inputs = sys.argv[2:]

    src = os.path.join(ROOT, "answers", name + ".c")
    with tempfile.TemporaryDirectory() as tmp:
        exe = os.path.join(tmp, name + (".exe" if os.name == "nt" else ""))
        r = subprocess.run(
            [CLANG, "-std=c11", "-Wall", "-Wextra", "-g", src, "-o", exe],
            capture_output=True,
            text=True,
        )
        if r.returncode != 0:
            print("COMPILE FAILED for", name)
            print(r.stderr)
            return 1
        if r.stderr.strip():
            print("WARNINGS for", name)
            print(r.stderr)

        # 把 fixture 复制进运行目录（需要输入文件的题目靠这个）
        fixture = os.path.join(CASES, name + ".fixture")
        if os.path.isdir(fixture):
            for fn in os.listdir(fixture):
                shutil.copy(os.path.join(fixture, fn), os.path.join(tmp, fn))

        for i, path in enumerate(inputs):
            if i == 0:
                in_suffix, out_suffix = ".in", ".out"
            else:
                in_suffix, out_suffix = f".{i+1}.in", f".{i+1}.out"

            with open(path, "r", encoding="utf-8") as f:
                data = f.read()

            with open(os.path.join(CASES, name + in_suffix), "w", encoding="utf-8") as f:
                f.write(data)

            run = subprocess.run(
                exe, input=data, capture_output=True, text=True, timeout=10, cwd=tmp
            )
            if run.returncode != 0:
                print(f"RUNTIME ERROR for {name} on {path}: rc={run.returncode}")
                print(run.stderr)
                return 1

            with open(os.path.join(CASES, name + out_suffix), "w", encoding="utf-8") as f:
                f.write(run.stdout)

            print(f"  {name}{in_suffix}: in={data.strip()!r} -> out={run.stdout.strip()!r}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
