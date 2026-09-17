#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""把块注释内部嵌套的 /* ... */ 改写成括号说明。

C 的块注释不能嵌套：注释里出现 /* 只会有 -Wcomment 警告，
但注释里出现 */ 会把它提前终止，导致后面一大段注释变成代码。

骨架文件的大段说明注释里常写示例代码，里面免不了带行尾注释。
这个脚本把注释框内部的行尾 /* ... */ 换成圆括号说明，保持语义不变。
"""

import glob
import re
import sys

INNER = re.compile(r"/\*(.*?)\*/")


def fix(path):
    with open(path, encoding="utf-8") as f:
        lines = f.readlines()

    out = []
    depth = 0
    changed = 0

    for line in lines:
        stripped = line.lstrip()
        # 只在"注释框内部的行"上动手：以 * 开头，且不是注释起止行
        in_block = depth > 0
        is_box_line = stripped.startswith("*") and not stripped.startswith("*/")

        if in_block and is_box_line and INNER.search(line):
            def repl(m):
                return "(" + m.group(1).strip() + ")"

            new = INNER.sub(repl, line)
            changed += 1
            line = new

        out.append(line)

        # 更新块注释深度。注意顺序：先处理内容，再统计本行的开关。
        depth += line.count("/*") - line.count("*/")
        if depth < 0:
            depth = 0

    if changed:
        with open(path, "w", encoding="utf-8") as f:
            f.writelines(out)
        print(f"{path}: 修正 {changed} 处")

    return changed


def main():
    total = 0
    for pattern in ("practice/*.c", "answers/*.c"):
        for path in sorted(glob.glob(pattern)):
            total += fix(path)
    print(f"共修正 {total} 处")
    return 0


if __name__ == "__main__":
    sys.exit(main())
