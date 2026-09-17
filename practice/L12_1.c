/*
 * L12_1 · 找字符串中最长的单词
 *
 * 【题目】（经典题）
 *   读入一行字符串（可能含空格和标点），找出其中最长的单词并输出。
 *   单词的定义：连续的字母（大小写都算）。非字母字符是分隔符。
 *   如果有多个同样长的，输出【最先出现的那个】。
 *
 * 【输入格式】
 *   一行字符串，长度不超过 200。
 *
 * 【输出格式】
 *   最长的单词，占一行。
 *   （题目保证至少有一个单词）
 *
 * 【样例】
 *   输入：hello world programming
 *   输出：programming
 *
 *   输入：a bb ccc
 *   输出：ccc
 *
 * 【思路：一趟扫描，边走边记录】
 *
 *   关键是用【两个下标/指针】：
 *       i 一路往后走
 *       每到一处，跳过非字母，然后标记单词起点，再走到单词结尾
 *
 *       int n = strlen(s);
 *       int i = 0;
 *       int bestLen = 0;            (已找到的最长长度)
 *       int bestStart = 0;          (最长单词的起始下标)
 *
 *       while (i < n) {
 *           (第一步：跳过非字母)
 *           while (i < n && !is_letter(s[i])) {
 *               i++;
 *           }
 *
 *           (第二步：记录单词起点)
 *           int start = i;
 *
 *           (第三步：走到单词结尾)
 *           while (i < n && is_letter(s[i])) {
 *               i++;
 *           }
 *
 *           (第四步：当前单词是 s[start..i-1]，长度 i-start)
 *           int len = i - start;
 *           if (len > bestLen) {        (← 用 > 而不是 >=)
 *               bestLen = len;
 *               bestStart = start;
 *           }
 *       }
 *
 * 【⚠️ 为什么用 `>` 而不是 `>=`】
 *   题目要求"有多个同样长的，输出最先出现的"。
 *   用 `>` 时，只有【严格更长】才更新，所以同样长的时候保留先找到的那个。✓
 *   用 `>=` 就会保留后找到的，不符合要求。
 *   这是这道题最容易错的地方，上机题常考。
 *
 * 【⚠️ 输出时怎么"截取"】
 *   不要试图修改原字符串。最简单的办法是【逐个字符打印】：
 *
 *       for (int k = 0; k < bestLen; k++) {
 *           printf("%c", s[bestStart + k]);
 *       }
 *       printf("\n");
 *
 *   也可以用 strncpy 复制到另一个数组再打印：
 *       char res[201];
 *       strncpy(res, s + bestStart, bestLen);
 *       res[bestLen] = '\0';            (⚠️ strncpy 不会自动加 \0！)
 *       printf("%s\n", res);
 *
 *   ⚠️ 【strncpy 的坑】它复制 n 个字符，但【不保证加 \0】。
 *      如果源字符串前 n 个字符里没有 \0，目标就不会有 \0。
 *      所以必须【手动加】res[bestLen] = '\0'。
 *      这是 strncpy 与 strcpy 最大的区别，也是常考的坑。
 *
 * 【is_letter 怎么写】
 *   没有现成的"是字母"函数，自己写：
 *
 *       int is_letter(char c)
 *       {
 *           return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
 *       }
 *
 *   🔸 用 `c - 'a'` 那样的技巧不行，这里要判断范围。
 *      记住这个惯用写法，字符串题里到处都要用。
 *
 * 【读一行】
 *   fgets(s, 201, stdin);
 *   s[strcspn(s, "\n")] = '\0';
 */

#include <stdio.h>
#include <string.h>

/* 判断是不是字母 */
int is_letter(char c)
{
    // TODO
    return 0;
}

int main(void)
{
    char s[201];
    int bestLen = 0;
    int bestStart = 0;

    fgets(s, 201, stdin);
    s[strcspn(s, "\n")] = '\0';

    // TODO: 一趟扫描，找出最长单词的起始位置和长度

    // 输出
    for (int k = 0; k < bestLen; k++) {
        printf("%c", s[bestStart + k]);
    }
    printf("\n");

    return 0;
}
