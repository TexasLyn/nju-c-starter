# 本仓库的维护约定

给 AI 助手和贡献者看的规则。**面向学习者的说明在 [README.md](README.md)，不是这里。**

## 改完必须跑验证

任何改动（讲义 / 题目 / 答案 / 测试数据 / 脚本）之后：

```bash
python3 tests/check.py --dir answers               # 期望：结果：通过 75
python3 tests/check.py --compile-only --dir practice  # 期望：通过 71 / 仅编译 4
```

那 4 道不通过的是 `L15_1`~`L15_3` 等**故意含错的改错题骨架**，标记是文件头部的 `@NOCOMPILE`，属正常。

改了 `tests/cases/` 里的期望输出就等于改判题标准，改动要能说出理由。

## 讲义写作规则

- **不假设读者会别的编程语言**。`docs/` 正文里不出现 Python 代码块，也不出现"你在 Python 里……"这类前提。（`docs/A-有编程基础怎么快速过.md` 是唯一的例外，它专门服务有基础的人。）
- 每课结尾保持三件套：**最少必要记忆** / **新手最常犯的 3 个错** / **本课练习**。
- 术语统一：`编译错误` / `逻辑错误`、`盒子`（变量的比喻）、`🔸` 表示"先记住写法，后面解释"、`⚠️` 表示"这里是地基，务必想清楚"。
- 讲义之间的相对链接改动后跑一遍链接检查（见下）。

## 不要写进仓库的东西

- 硬编码绝对路径（`/Users/xxx/...`）。
- 校名、专业名、具体课程号。
- 编译产物、`__pycache__`、程序运行时生成的 `result.txt` / `output.txt`。

`.gitignore` 里**不要**加 `*.out` —— 会连带忽略 `tests/cases/*.out`（那是必须入库的期望输出）。要忽略的产物写精确路径。

## 常用维护脚本

`tools/` 里的脚本都是给维护者用的，不是教程内容：

| 脚本 | 用途 |
|---|---|
| `tools/neutralize.py` | 批量把"面向某门具体课程"的措辞改成中性表述（长短语优先 + 占位符保护，避免短串误伤） |
| `tools/gen_cases.py` | 编译 `answers/<题名>.c` 跑出 `.out` 期望文件 |
| `tools/fix_nested_comments.py` | 把骨架注释里嵌套的 `/* */` 改写成括号说明（C 块注释不能嵌套） |

## 链接检查

改过目录结构或文件重命名之后：

```bash
python3 - <<'EOF'
import os, re, glob
bad = 0
for f in glob.glob("**/*.md", recursive=True):
    base = os.path.dirname(f)
    for m in re.finditer(r'\[[^\]]*\]\(([^)#]+?)\)', open(f, encoding="utf-8").read()):
        t = m.group(1)
        if t.startswith(("http", "mailto")):
            continue
        if not os.path.exists(os.path.normpath(os.path.join(base, t))):
            print("BROKEN", f, "->", t); bad += 1
print("broken links:", bad)
EOF
```

## 提交信息

用 `<type>: <一句话>` 开头（`feat` / `fix` / `docs` / `refactor` / `chore`），正文说清**为什么**改，以及验证结果。

改了题目或答案的提交，正文里附上评测脚本的输出。

## 上下文习惯

- 批量同类改动（比如全仓库措辞替换）**写脚本一次做完**，不要逐个文件 Read + Edit。
- 大文件只读相关段落（offset / limit）。
- 跑命令用 `| tail -n` / `grep` 收窄输出，不要把整段日志倒进上下文。
- 一个阶段做完就收尾，别把中间产物一直堆在对话里。
