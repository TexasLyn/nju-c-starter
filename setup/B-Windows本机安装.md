# B · Windows 本机安装（手把手）

> **这条路的承诺**：跟着做 30 分钟，之后你就有完整的 C 环境——能编译、能运行、能一键判题。
> **完全没装过开发工具也能走**，每一步都写了你会看到什么。

---

## 0. 先搞清楚我们要装什么

三个东西，都很小：

| 装什么 | 是什么 | 干什么用 | 大小 |
|---|---|---|---|
| **MinGW-w64** | 一个 C 编译器（含 `gcc`） | 把你的 `.c` 代码翻译成能运行的程序 | ~150 MB |
| **Python 3** | 一个解释器 | 跑本仓库的自动判题脚本 `tests/check.py` | ~30 MB |
| **VS Code** | 代码编辑器 | 写代码的地方（比记事本好用一万倍） | ~100 MB |

💡 **想省事的话**：VS Code 可以用任何编辑器代替（记事本也行，只是难用）。但**编译器必须装**，Python 最好装上（不然要手动对答案）。

---

## 1. 装 MinGW-w64（编译器）

### 方式一：winget（推荐，最快）

按 `Win + R`，输入 `powershell`，回车，会弹出一个蓝底窗口。把下面这行粘进去回车：

```powershell
winget install -e --id BrechtSanders.WinLibs.POSIX.UCRT
```

它会下载并自动安装。装完**关掉这个窗口，重新开一个**（这很重要，让系统认到新装的命令）。

新窗口里输入：

```powershell
gcc --version
```

**应该看到类似这样的输出**（版本号不用一样）：

```
gcc (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 15.1.0
```

**看到版本号 = 成功。**

---

### 方式二：手动下载（winget 用不了时）

1. 打开 https://www.mingw-w64.org/downloads/
2. 找 **MinGW-W64-builds** 那一栏，点进去（或者直接搜 "winlibs mingw-w64 download"）
3. 下载那个 `.7z` 或 `.zip` 压缩包（名字里有 `x86_64`、`posix`、`ucrt` 的，随便挑一个都行）
4. 解压到一个**不长、不含中文、不含空格**的路径，比如 `C:\mingw64`
5. 把 `C:\mingw64\bin` 加进系统 PATH：
   - 按 `Win`，搜「环境变量」，点「编辑系统环境变量」
   - 点「环境变量」按钮
   - 在**下面的**「系统变量」列表里找到 `Path`，选中，点「编辑」
   - 点「新建」，输入 `C:\mingw64\bin`，一路「确定」
6. **关掉所有命令行窗口，重新开一个**，输入 `gcc --version` 验证

⚠️ **加了 PATH 一定要重开窗口**，否则系统还是找不到 `gcc`。这是新手最常卡住的地方。

---

## 2. 装 Python 3

在 PowerShell 里：

```powershell
winget install -e --id Python.Python.3.12
```

装完**关掉窗口重新开**，验证：

```powershell
python --version
```

应该输出 `Python 3.12.x`。

⚠️ **如果提示"无法将 python 项识别为..."**：装的时候有一个「Add Python to PATH」的勾选项，如果没勾，就得手动加 PATH（和上面 MinGW 的步骤一样，把 Python 安装目录和它的 `Scripts` 子目录都加进去）。

---

## 3. 装 VS Code（写代码的地方）

```powershell
winget install -e --id Microsoft.VisualStudioCode
```

装完后，打开 VS Code，左边栏点那个方块图标（Extensions），搜索并安装这两个扩展：

| 扩展名 | 干什么用的 |
|---|---|
| **C/C++**（作者 Microsoft） | 语法高亮、报错提示 |
| **Chinese (Simplified)** | 中文界面（可选） |

---

## 4. 把材料拿到本地

如果你是从 GitHub 下载的：

1. 在仓库页面点绿色的 **Code** 按钮 → **Download ZIP**
2. 解压到一个**不含中文和空格**的路径，比如 `C:\Users\你的用户名\c-starter`

⚠️ **不要放在「桌面」或「下载」这种中文路径下**，也不要放在 OneDrive 同步目录里（会导致编译产物被同步、随机报错）。

用命令行验证一下：

```powershell
cd C:\Users\你的用户名\c-starter
dir
```

应该看到 `docs`、`practice`、`answers`、`tests`、`setup` 这些目录。

---

## 5. 验证：跑通全套评测

这是**最关键的一步**。在 `c-starter` 目录下输入：

```powershell
python tests\check.py --dir answers
```

⚠️ Windows 上用 `python` 而不是 `python3`，路径用反斜杠 `\`。

**等它跑一会儿，最后应该看到：**

```
结果：通过 75
```

**看到这一行，你的环境就完全通了。**

如果报错，跳到本文最后的「出问题怎么办」。

---

## 6. 跑你自己的第一道题

```powershell
cd practice
gcc -std=c11 -Wall -Wextra -g L01_1.c -o L01_1.exe
.\L01_1.exe
```

⚠️ **注意 `.\`** —— Windows 的 PowerShell 里运行当前目录的程序必须写 `.\`，只写 `L01_1` 会找不到。

程序要输入的时候，直接敲数字按回车。

### 用评测脚本判题（推荐）

回到仓库根目录：

```powershell
cd ..
python tests\check.py L01_1 --dir practice
```

它会编译你的代码、喂测试数据、和标准答案比对，然后告诉你**哪一行不一样**。

---

## 7. 日常怎么用

### 写代码

用 VS Code 打开 `practice` 目录，双击某个 `.c` 文件开始写。文件开头注释里就是题目。

### 运行

在 VS Code 里按 `Ctrl + 反引号`（键盘左上角 `Esc` 下面那个键）打开终端，然后：

```powershell
gcc -std=c11 -Wall -Wextra -g practice\L01_1.c -o L01_1.exe; .\L01_1.exe
```

### 判题

```powershell
python tests\check.py L01_1
```

### 关于 CLion（可选）

如果你有 CLion 或者 JetBrains 学生账号，也可以用 CLion 打开这个目录——它认识 `CMakeLists.txt`，会自动为每个 `.c` 文件生成一个可运行目标，右上角下拉框选题目名点绿三角就能跑，比敲命令方便。**但这不是必需的**，上面的命令行方式已经够了。

---

## 出问题怎么办

### `gcc` 或 `python` 提示"不是内部或外部命令"

PATH 没配好，或者**没重开窗口**。关掉所有命令行窗口，重新开一个再试。还不行就回到第 1 节的 PATH 步骤检查。

### 编译报错 `error: 'for' loop initial declarations are only allowed in C99 mode`

说明编译器太老。本仓库的代码需要 C11。检查：

```powershell
gcc --version
```

版本低于 5 的话换上面方式二里的新版 MinGW。

### 中文输出变成乱码

Windows 控制台默认编码可能不是 UTF-8。两个办法：

**办法一（推荐）**：在 `main` 函数第一行加一句：

```c
#include <windows.h>   /* 只在 Windows 上需要 */
...
int main(void) {
    SetConsoleOutputCP(65001);   /* 让控制台用 UTF-8 */
    ...
}
```

**办法二**：把练习里的中文输出改成英文，先专心练语法（考试卷面语言不受影响）。

⚠️ **注意**：加了 `#include <windows.h>` 的代码**在 macOS / Linux 上编译不过**。所以如果你在两种系统间来回切换，别把这个改动提交到共享的代码里。

### 评测脚本报 `找不到 C 编译器`

脚本找不到 `gcc`。回到第 1 节确认 `gcc --version` 在**新开的**窗口里能跑通。

### 评测脚本报编码错误 / 中文乱码

PowerShell 的编码设置问题，先执行这一行再跑脚本：

```powershell
$env:PYTHONUTF8=1
```

### 程序运行后窗口一闪而过

在 VS Code 的终端里运行（`Ctrl + 反引号`），不要在资源管理器里双击 `.exe`。

### 杀毒软件报毒

MinGW 编译出来的 `.exe` 有时会被国产杀毒软件误报（因为没有签名）。把 `c-starter` 目录加进白名单。

---

下一个 → 环境通了就去 [docs/01 · 第一个 C 程序](../docs/01-第一个C程序.md)；想让 AI 陪你学就去看 [D · 让 AI 当你的助教](D-让AI当你的助教.md)
