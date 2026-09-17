#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""开源化清理第二步：把"面向某一门具体课程"的措辞改成面向所有自学者的措辞。

用法（在仓库根目录执行）：

    python3 tools/neutralize.py            # 实际改写
    python3 tools/neutralize.py --dry-run  # 只看会改哪些地方

只动文档和注释里的文字，不改任何代码逻辑。

实现要点：先把长短语替换成占位符保护起来，再跑词级规则，
最后把占位符换回目标文字。否则"经典教材"会被后面的"教材→老教材"再改一次。
"""

import argparse
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SELF = os.path.abspath(__file__)

# 第一趟：整句改写（会包含下面词级规则里的词，所以必须先做并用占位符保护）
PHRASES = [
    ("期末上机考试", "上机考试"),
    ("上机考试的两道编程题", "上机题里的两道编程题"),
    ("上机考试第一题", "上机题的第一题"),
    ("上机考试的结构是", "上机题的结构通常是"),
    ("上机考试最常见", "上机题最常见"),
    ("上机考试常见题型", "上机常见题型"),
    ("上机考题的典型结构", "上机题的典型结构"),
    ("上机考题", "上机题"),
    ("期末编程练习", "编程练习"),
    ("期末上机冲刺", "上机实战冲刺"),
    ("根据课程提供的模拟试卷，", ""),
    ("改错题的评分规则很特别，模拟卷里的原话大意是：", "改错题通常还有一条特别的评分规则："),
    ("## 6. 模拟卷里出现过的编程题（了解难度）", "## 6. 常见的上机编程题（了解难度）"),
    ("从模拟试卷里摘几道，你可以感受一下难度：", "下面几道是上机题里反复出现的类型，可以感受一下难度："),
    ("### 从模拟试卷里看到的真实要求", "### 从典型上机题里看到的真实要求"),
    ("编程练习的编程题长这样（摘自模拟卷）：", "典型的编程题长这样："),
    ("模拟试卷", "典型上机题"),
    ("模拟卷", "上机题"),
    ("老师收卷时会去检查这个文件的内容", "判题时会去检查这个文件的内容"),
    ("老师收卷时看到的是空文件或者不完整的内容", "判题时看到的就是空文件或者不完整的内容"),
    ("考试时老师就是这样检查你的结果对不对", "判题时就是这样检查你的结果对不对"),
    ("老师那边会在他自己的工作目录里找", "判题程序会在它自己的工作目录里找"),
    ("老师是用 VS2010 那套环境评的", "有些老环境只支持教材写法"),
    ("老师用 VS2010 那套环境评的", "有些老环境只支持教材写法"),
    ("老师用 VS2010 环境评", "有些老环境只支持教材写法"),
    ("（老师收作业用的）", "（交出去的程序文件名）"),
    ("老师发的 docx", "原始题目文档"),
    ("教材和考试都用", "经典教材和上机题都用"),
    ("教材/考试主流", "常见教材里的主流写法"),
    ("教材写法", "教材写法"),
    ("| 教材写法 | 本机替换 |", "| 教材写法 | 现代写法 |"),
    ("你的教材和参考答案里用", "不少教材和参考答案里用"),
    ("教材里的", "教材里的"),
    ("教材里可能会提", "教材里可能会提"),
    ("教材基本不用", "教材基本不用"),
    ("交作业按教材写法", "按教材写法提交"),
    ("写作业一律用", "一律用"),
    ("作业里的题经常要精确到", "练习里经常要精确到"),
    ("作业里经常要输出表格", "经常要输出表格"),
    ("作业和考试里最容易丢分", "练习和上机题里最容易丢分"),
    ("考试爱考，作业也常用", "上机题爱考，平时也常用"),
    ("作业和考试里最常见的题型", "练习和上机题里最常见的题型"),
    ("这类题在作业里占的分量不小", "这类题在练习里占的分量不小"),
    ("作业和考试里很常见", "练习和上机题里很常见"),
    ("作业里有些题要求用全局变量", "有些题目会要求用全局变量"),
    ("作业里题目说了用哪种就用哪种", "题目说了用哪种就用哪种"),
    ("作业里有这么一道题", "有一类经典题目"),
    ("作业里非常常见", "实际代码里非常常见"),
    ("注意作业里的函数签名", "注意这类题目的函数签名"),
    ("这就是作业里", "这就是"),
    ("作业里第一个参数用", "第一个参数用"),
    ("作业里要求“输入 n 然后处理 n 个数”", "遇到“输入 n 然后处理 n 个数”"),
    ("作业里要求\"输入 n 然后处理 n 个数\"", "遇到\"输入 n 然后处理 n 个数\""),
    ("作业里也总是给你 n 或者让你自己数", "这类题目里也总是给你 n 或者让你自己数"),
    ("学期作业", "课后练习"),
]

# 第二趟：词级替换（全局，但已被占位符保护的部分不受影响）
WORDS = [
    ("上机考", "上机练习"),
    ("期末笔试", "笔试"),
    ("教材", "老教材"),
    ("老师", "任课老师"),
    ("作业", "练习"),
]

# 第三趟：清掉规则叠加产生的重复词
FIXUPS = [
    ("老老教材", "老教材"),
    ("任课任课老师", "任课老师"),
    ("练习练习", "练习"),
    ("上机上机", "上机练习"),
    ("上机练习练习", "上机练习"),
    ("课后练习练习", "课后练习"),
]

PATTERNS = [
    "practice/*.c",
    "answers/*.c",
    "docs/*.md",
    "docs/for-python-devs/*.md",
    "tests/*.py",
    "CMakeLists.txt",
    "README.md",
    "setup/*.md",
    "prompts/*.md",
]


def neutralize(text):
    """返回 (新文本, 命中次数)。"""
    hits = 0
    store = []

    def protect(m):
        store.append(m.group(1))
        return "\x00%d\x00" % (len(store) - 1)

    out = text
    # 第一趟：长短语 → 占位符
    for old, new in sorted(PHRASES, key=lambda kv: -len(kv[0])):
        if old not in out:
            continue
        store.append(new)
        idx = len(store) - 1
        n = out.count(old)
        out = out.replace(old, "\x00%d\x00" % idx)
        hits += n

    # 第二趟：词级替换
    for old, new in WORDS:
        n = out.count(old)
        if n:
            out = out.replace(old, new)
            hits += n

    # 第三趟：还原占位符
    out = re.sub(r"\x00(\d+)\x00", lambda m: store[int(m.group(1))], out)

    for bad, good in FIXUPS:
        while bad in out:
            out = out.replace(bad, good)

    return out, hits


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    files = []
    for pat in PATTERNS:
        files.extend(glob.glob(os.path.join(ROOT, pat)))

    total_files = 0
    total_hits = 0
    for path in sorted(set(files)):
        if os.path.abspath(path) == SELF:
            continue
        with open(path, encoding="utf-8") as f:
            src = f.read()
        out, hits = neutralize(src)
        if hits:
            total_files += 1
            total_hits += hits
            print(f"{os.path.relpath(path, ROOT)}: {hits} 处")
            if not args.dry_run:
                with open(path, "w", encoding="utf-8") as f:
                    f.write(out)

    print()
    print(f"{'将' if args.dry_run else '已'}修改 {total_files} 个文件，共 {total_hits} 处")
    return 0


if __name__ == "__main__":
    sys.exit(main())
