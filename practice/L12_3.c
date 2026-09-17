/*
 * L12_3 · 删除不符合 C 标识符命名规则的字符串
 *
 * 【题目】（经典题）
 *   读入若干行字符串（每行一个，以 "END" 结束输入），
 *   删掉其中【不符合 C 标识符命名规则】的，
 *   把剩下合法的按原顺序输出。
 *
 * 【C 标识符命名规则】
 *       1. 只能由字母（大小写）、数字、下划线 _ 组成
 *       2. 【不能以数字开头】
 *       3. 不能为空
 *
 *   合法的例子：abc、_x1、sum_2、A
 *   不合法的例子：1abc（数字开头）、a-b（有减号）、a b（有空格）、x.y
 *
 * 【输入格式】
 *   若干行，每行一个字符串（不含空格，长度不超过 50），
 *   最后一行是 END（不区分大小写，eN d 等也算）表示结束。
 *
 * 【输出格式】
 *   合法的字符串，每行一个，按原顺序。
 *
 * 【样例】
 *   输入：
 *   abc
 *   1abc
 *   _x1
 *   a-b
 *   sum_2
 *   END
 *   输出：
 *   abc
 *   _x1
 *   sum_2
 *
 * 【思路：写一个判断函数，然后逐行过滤】
 *
 *       int is_valid(char *s)
 *       {
 *           if (s[0] == '\0') return 0;                  (空串)
 *           if (s[0] >= '0' && s[0] <= '9') return 0;    (数字开头)
 *
 *           for (int i = 0; s[i] != '\0'; i++) {
 *               char c = s[i];
 *               int ok = (c >= 'a' && c <= 'z')
 *                     || (c >= 'A' && c <= 'Z')
 *                     || (c >= '0' && c <= '9')
 *                     || (c == '_');
 *               if (!ok) return 0;                       (有非法字符)
 *           }
 *
 *           return 1;
 *       }
 *
 * 【⚠️ 为什么"数字开头"要单独判断】
 *   因为数字是"可以作为后续字符、但不能作为首字符"的。
 *   循环里的字符集检查允许数字，所以必须【额外】检查第一位。
 *   这是本题最容易漏的地方——很多人只写了字符集检查，
 *   结果 "1abc" 被判成合法。
 *
 * 【⚠️ 怎么判断读到 END 了】
 *   用 strcmp，且要处理大小写。两种做法：
 *
 *   做法 A：把输入统一转成大写再比
 *       char up[100];
 *       for (int i = 0; s[i]; i++) up[i] = toupper(s[i]);   (需要 ctype.h)
 *       up[strlen(s)] = '\0';
 *       if (strcmp(up, "END") == 0) break;
 *
 *   做法 B：分别比较（简单直接）
 *       if (strcmp(s, "END") == 0 || strcmp(s, "end") == 0
 *           || strcmp(s, "End") == 0 || strcmp(s, "eNd") == 0) ...
 *       太啰嗦，不推荐。
 *
 *   做法 C：本题只要求全大写 END，那最简单：
 *       if (strcmp(s, "END") == 0) break;
 *
 *   我们按做法 C 实现（测试数据用全大写 END）。
 *   如果你想更健壮，用做法 A，加 #include <ctype.h>。
 *
 * 【读一行的方式】
 *   用 fgets 循环读，每读一行处理一行：
 *
 *       char s[100];
 *       while (fgets(s, 100, stdin) != NULL) {
 *           s[strcspn(s, "\n")] = '\0';      (去掉换行)
 *           if (strcmp(s, "END") == 0) break;
 *           if (is_valid(s)) printf("%s\n", s);
 *       }
 *
 *   ⚠️ `fgets(...) != NULL` 是标准写法：fgets 读到文件结尾会返回 NULL。
 *      在终端里手动输入时用 Ctrl+D（macOS）表示结束。
 *      但这道题有 END 作为结束标志，所以主要靠 strcmp 判断。
 */

#include <stdio.h>
#include <string.h>

/* 判断字符串是否是合法的 C 标识符 */
int is_valid(char *s)
{
    // TODO
    return 0;
}

int main(void)
{
    char s[100];

    while (fgets(s, 100, stdin) != NULL) {
        s[strcspn(s, "\n")] = '\0';

        if (strcmp(s, "END") == 0) {
            break;
        }

        // TODO: 如果 is_valid(s) 就输出
    }

    return 0;
}
