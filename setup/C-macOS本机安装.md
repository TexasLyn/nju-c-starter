# C · macOS 本机安装（手把手）

> **这条路的承诺**：跟着做 15 分钟，之后你就有完整的 C 环境。
> macOS 比 Windows 省事得多，因为自带的工具链里就有 `clang`。

---

## 0. 先搞清楚我们要装什么

比 Windows 少一步：

| 装什么 | 是什么 | 状态 |
|---|---|---|
| **clang 编译器** | 苹果的 C 编译器 | **系统自带**，但需要激活一下 |
| **Python 3** | 跑评测脚本用 | macOS 自带 python3，通常不用装 |
| **编辑器** | 写代码的地方 | VS Code（推荐）或系统自带的 TextEdit |

---

## 1. 激活编译器

打开「终端」：按 `Cmd + 空格`，输入 `terminal`，回车。

在终端里输入（可以直接复制整行粘贴）：

```bash
xcode-select --install
```

会弹出一个对话框问你「要安装命令行开发者工具吗」，点**安装**，同意许可协议。

⚠️ **注意**：弹出的**不是**几 GB 的 Xcode，是只有几百 MB 的命令行工具。别点错。

下载安装大概 5~15 分钟（看网速）。装完验证：

```bash
clang --version
```

应该看到：

```
Apple clang version 15.0.0 (clang-1500.3.9.4)
```

**看到版本号 = 成功。**

⚠️ **如果提示 "command line tools are already installed"** —— 好事，说明你以前装过了，直接跳到第 2 步。

---

## 2. 确认 Python 3

macOS 现在都自带 python3，验证一下：

```bash
python3 --version
```

应该输出 `Python 3.11.x` 或更高。

⚠️ **如果提示找不到 python3**：用 Homebrew 装（`brew install python3`），或者去 https://www.python.org/downloads/ 下载安装包。装完重开终端。

⚠️ **注意区分 `python` 和 `python3`**：macOS 上 `python` 可能指向一个很老的 Python 2，**本仓库的脚本一律用 `python3`**。

---

## 3. 装 VS Code（写代码的地方）

**方式一：下载**（推荐新手）

打开 https://code.visualstudio.com/ 点那个大按钮下载，然后把下载的 `.zip` 解开，把 `Visual Studio Code.app` 拖进「应用程序」文件夹。

**方式二：Homebrew**（如果你装了 brew）

```bash
brew install --cask visual-studio-code
```

装完后打开 VS Code，左边栏点方块图标（Extensions），搜索并安装：

| 扩展名 | 干什么用的 |
|---|---|
| **C/C++**（作者 Microsoft） | 语法高亮、报错提示 |

---

## 4. 把材料拿到本地

如果你是从 GitHub 下载的：

1. 在仓库页面点绿色的 **Code** → **Download ZIP**
2. 解压，把文件夹放到你的用户目录下，比如 `/Users/你的用户名/c-starter`

⚠️ **建议放在用户目录或 Documents 下**，不要放在 iCloud Drive 同步的桌面/文稿里（同步会拖慢编译、偶尔导致文件锁冲突）。

在终端验证：

```bash
cd ~/c-starter
ls
```

应该看到 `docs`、`practice`、`answers`、`tests`、`setup` 这些目录。

---

## 5. 验证：跑通全套评测

**最关键的一步。** 在 `c-starter` 目录下：

```bash
python3 tests/check.py --dir answers
```

**等它跑一会儿，最后应该看到：**

```
结果：通过 75
```

**看到这一行，环境就完全通了。**

---

## 6. 跑你自己的第一道题

```bash
cd practice
clang -std=c11 -Wall -Wextra -g L01_1.c -o /tmp/L01_1 && /tmp/L01_1
```

⚠️ **`-Wall -Wextra` 一定要加**，它们会打开所有警告，很多 bug 靠警告才能发现。

程序要输入的时候，直接敲数字按回车。

### 用评测脚本判题（推荐）

```bash
cd ..
python3 tests/check.py L01_1 --dir practice
```

它会编译你的代码、自动喂输入、和标准答案比对，然后**指出哪一行不一样**。

---

## 7. 日常怎么用

### 写代码

用 VS Code 打开 `practice` 目录（`code practice`），双击某个 `.c` 文件开始写。

### 运行

VS Code 里按 `Ctrl + 反引号`（键盘左上角）打开终端：

```bash
clang -std=c11 -Wall -Wextra -g practice/L01_1.c -o /tmp/L01_1 && /tmp/L01_1
```

### 判题

```bash
python3 tests/check.py L01_1
```

### 关于 CLion（可选）

有 CLion 的话，用它打开这个目录最舒服：它认识 `CMakeLists.txt`，会**自动为每个 `.c` 文件生成一个可运行目标**，右上角下拉框选题目名点绿三角就能跑，程序要输入时在下面的运行窗口里直接敲。**但不是必需的**，命令行方式已经够用。

---

## mac 独有的几个坑

### ① `gets()` 和 `conio.h` 用不了

老教材和很多学校的参考答案里有这两样东西：

```c
#include <conio.h>    /* ✗ macOS 上不存在这个头文件 */
clrscr();             /* ✗ 清屏函数，不存在 */
gets(str);            /* ✗ 因为不安全，已被 C 标准删除 */
```

**替换对照表**：

| 教材写法 | macOS 上用这个 |
|---|---|
| `#include <conio.h>` | 删掉这一行 |
| `clrscr();` | 删掉这一句 |
| `gets(str);` | `fgets(str, sizeof(str), stdin);` 然后去掉末尾换行 |

`fgets` 的完整用法（会保留换行符，所以要手动去掉）：

```c
char str[100];
fgets(str, sizeof(str), stdin);
str[strcspn(str, "\n")] = '\0';    /* 去掉末尾换行，第 12 课讲原理 */
```

🔸 **重要**：如果你所在的课程要求按教材写法提交（有些老环境只认那套写法），那就**本机练习用现代写法、交上去用教材写法**。两套写法讲义里都会给。

### ② Apple 的 clang 对"调用了没声明的函数"零容忍

```c
printf("%f\n", sqrt(16.0));    /* ✗ 报错：call to undeclared library function 'sqrt' */
```

老编译器只给个警告，Apple clang 直接当**错误**处理。所以**漏 `#include` 会直接编译失败**。这其实是好事——错误早暴露。

**报错里看到 `undeclared function`，第一反应就是"是不是漏了某个 `#include`"。**

### ③ 用 `math.h` 不用加 `-lm`

老 Linux 上要写 `gcc x.c -o x -lm`，**macOS 上不需要**。

---

## 出问题怎么办

### `xcode-select --install` 弹窗点了没反应

可能是网络问题（这个下载走苹果服务器）。试试：

```bash
sudo rm -rf /Library/Developer/CommandLineTools
xcode-select --install
```

或者去 https://developer.apple.com/download/all/ 手动下载 Command Line Tools 安装（需要 Apple ID，免费）。

### 提示 `xcrun: error: invalid active developer path`

命令行工具的路径丢了，通常发生在系统大版本升级之后。重装：

```bash
xcode-select --install
```

### 编译报了 `non-ASCII characters are not allowed outside of literals and identifiers`

**中文标点混进代码里了。** 这是中文用户最常见的问题，因为中英文标点在屏幕上几乎长得一样。

检查 `（）`、`；`、`，`、`“”` 这些全角符号，换成半角的 `()`、`;`、`,`、`""`。

### 终端提示 `permission denied`

不要用 `sudo` 编译。如果是 `/tmp` 权限问题，改用 `-o ./L01_1` 输出到当前目录。

### 想看一个程序到底输出了什么，但输出太多

```bash
clang -std=c11 -Wall -Wextra -g practice/L01_1.c -o /tmp/L01_1 && /tmp/L01_1 | head -20
```

`| head -20` 表示只看前 20 行。

---

下一个 → 环境通了就去 [docs/01 · 第一个 C 程序](../docs/01-第一个C程序.md)；想让 AI 陪你学就去看 [D · 让 AI 当你的助教](D-让AI当你的助教.md)
