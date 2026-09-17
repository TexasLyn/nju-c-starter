/*
 * L12_2 · 子串替换（经典题）
 *
 * 【题目】
 *   实现函数：
 *
 *       int replace_str(char *s, char *t, char *g)
 *
 *   作用：把字符串 s 中【所有】出现的子串 t 替换成 g，返回替换的次数。
 *   替换后的结果要【写回 s】。
 *
 * 【输入格式】
 *   三行：
 *   第一行：原字符串 s
 *   第二行：要被替换的子串 t
 *   第三行：替换成的子串 g
 *
 * 【输出格式】
 *   第一行：替换次数
 *   第二行：替换后的字符串
 *
 * 【样例】
 *   输入：
 *   hello world
 *   o
 *   0
 *   输出：
 *   2
 *   hell0 w0rld
 *
 *   输入：
 *   abcabc
 *   abc
 *   XY
 *   输出：
 *   2
 *   XYXY
 *
 * 【⚠️ 最容易想到但错误的做法】
 *
 *   "用 strstr 找到位置，然后 strcpy 覆盖" —— 这样会出错：
 *       - 如果 g 比 t 长，会覆盖掉后面还没处理的内容
 *       - 如果 g 比 t 短，会留下空隙
 *
 *   所以不能原地改。正确做法是【边扫描边写入另一个缓冲区】：
 *
 *       int replace_str(char *s, char *t, char *g)
 *       {
 *           char buf[1024];              (结果缓冲区)
 *           int cnt = 0;
 *           int tl = strlen(t);
 *           char *p = s;
 *           buf[0] = '\0';               (⚠️ 必须先置空，才能用 strcat)
 *
 *           while (*p != '\0') {
 *               if (strncmp(p, t, tl) == 0) {
 *                   (匹配上了：把 g 接上去，跳过 t)
 *                   strcat(buf, g);
 *                   p = p + tl;
 *                   cnt++;
 *               } else {
 *                   (没匹配上：把这个字符接上去，前进一格)
 *                   int l = strlen(buf);
 *                   buf[l] = *p;
 *                   buf[l + 1] = '\0';
 *                   p++;
 *               }
 *           }
 *
 *           strcpy(s, buf);              (结果写回 s)
 *           return cnt;
 *       }
 *
 * 【⚠️ 三个关键点】
 *
 *   1. `buf[0] = '\0';` 必须在最前面。
 *      strcat 是从"当前 \0 的位置"往后接的。
 *      如果 buf 没有初始化，它的内容就是垃圾，strcat 会接到垃圾后面去。
 *      【这是最常见的错误，务必检查。】
 *
 *   2. 手工追加单个字符要写两句：
 *          int l = strlen(buf);
 *          buf[l] = *p;
 *          buf[l + 1] = '\0';       (← 别忘了补 \0)
 *      因为字符串必须以 \0 结尾，每加一个字符都要维护这个结尾。
 *
 *   3. `p = p + tl` 是【跳过整个 t】，不是只跳一格。
 *      这是"替换后不重复处理"的关键。
 *
 * 【strncmp 的用法】
 *   `strncmp(p, t, tl) == 0` 的意思是"从 p 开始的 tl 个字符，和 t 相同"。
 *   用它来判断"当前位置是否匹配子串 t"。
 *
 *   ⚠️ 如果 p 后面剩下的字符比 tl 少，strncmp 也能正确工作
 *      （它会遇到 \0 就返回非 0），所以不用额外检查长度。
 *
 * 【为什么用一个 1024 的缓冲区】
 *   因为替换后的长度可能比原来长（g 比 t 长时），也可能短。
 *   用一个足够大的缓冲区最省事。
 *   ⚠️ 真实工程里要考虑缓冲区大小够不够，题目数据规模小，1024 够了。
 */

#include <stdio.h>
#include <string.h>

/* 把 s 中所有 t 替换成 g，返回替换次数，结果写回 s */
int replace_str(char *s, char *t, char *g)
{
    // TODO
    return 0;
}

int main(void)
{
    char s[1024];
    char t[100];
    char g[100];

    fgets(s, 1024, stdin);
    s[strcspn(s, "\n")] = '\0';

    fgets(t, 100, stdin);
    t[strcspn(t, "\n")] = '\0';

    fgets(g, 100, stdin);
    g[strcspn(g, "\n")] = '\0';

    int cnt = replace_str(s, t, g);

    printf("%d\n", cnt);
    printf("%s\n", s);

    return 0;
}
