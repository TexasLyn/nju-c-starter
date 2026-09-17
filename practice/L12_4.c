/*
 * L12_4 · 找出不含元音的单词并按字典序输出（经典题）
 *
 * 【题目】
 *   实现函数：
 *
 *       int FindNoVowel(char *str[], int num, char res[][20])
 *
 *   作用：从 str 指向的 num 个单词中，找出【不含任何元音字母】的单词，
 *        存进 res（每个单词一行），并按【字典序从小到大】排好，
 *        返回这样的单词个数。
 *
 *   元音字母是：a e i o u（大小写都算）。
 *
 * 【输入格式】
 *   第一行：单词个数 num
 *   接下来 num 行：每行一个单词（不含空格，长度不超过 19）
 *
 * 【输出格式】
 *   第一行：不含元音的单词个数
 *   接下来每行一个：这些单词，按字典序 a→z 排列（大小写按 ASCII 比较）
 *
 * 【样例】
 *   输入：
 *   5
 *   sky
 *   rhythm
 *   try
 *   apple
 *   fly
 *   输出：
 *   4
 *   fly
 *   rhythm
 *   sky
 *   try
 *
 * 【函数参数的含义（本课重点）】
 *
 *   `char *str[]`  ——  指针数组，每个元素是一个单词的地址
 *   `int num`      ——  单词个数
 *   `char res[][20]` —— 二维字符数组，用来存结果（每行最多 20 字节）
 *
 *   ⚠️ 注意 `char res[][20]` 的列数 20 是【必须写】的（第 11 课讲过），
 *      因为函数里要用 sizeof 或者算地址时需要知道每行多大。
 *
 *   ⚠️ `char *str[]` 和 `char **str` 等价，都是"指向指针的指针"。
 *      用 `char *str[]` 更清楚地表达"这是个字符串数组"。
 *
 * 【为什么要用指针数组】
 *   因为要对单词排序！排序要交换元素。
 *   - 用指针数组：交换两个指针，一次赋值就行，超快
 *   - 用二维数组：要用 strcpy 复制整个字符串，慢且麻烦
 *
 * 【第一步：找出不含元音的单词】
 *
 *       int has_vowel(char *w)
 *       {
 *           for (int i = 0; w[i] != '\0'; i++) {
 *               char c = w[i];
 *               if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
 *                || c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
 *                   return 1;                        (有元音)
 *               }
 *           }
 *           return 0;                                (一个元音都没有)
 *       }
 *
 *       int m = 0;
 *       for (int i = 0; i < num; i++) {
 *           if (!has_vowel(str[i])) {
 *               strcpy(res[m], str[i]);              (复制进结果)
 *               m++;
 *           }
 *       }
 *
 * 【第二步：把 res 的 0..m-1 行按字典序排序】
 *   用简单选择排序 + strcmp 比较 + 整行交换：
 *
 *       for (int i = 0; i < m; i++) {
 *           for (int j = i + 1; j < m; j++) {
 *               if (strcmp(res[i], res[j]) > 0) {    (res[i] 更大)
 *                   char t[20];
 *                   strcpy(t, res[i]);               (三句交换)
 *                   strcpy(res[i], res[j]);
 *                   strcpy(res[j], t);
 *               }
 *           }
 *       }
 *
 *   ⚠️ 交换字符串【必须用 strcpy】，不能写成：
 *          char t[20];
 *          t = res[i];              (✗ 数组不能整体赋值)
 *   🔸 这是本课反复强调的点：数组的"整体赋值"在 C 里不存在，
 *      要用 strcpy（字符串）或者 for 循环（普通数组）。
 *
 * 【strcmp 的字典序规则】
 *   `strcmp(a, b) > 0` 表示 a 排在 b 后面（a "更大"）。
 *   比较方式是从第一个字符开始逐位比 ASCII 值。
 *   大小写按 ASCII：大写字母（65-90）比小写（97-122）小，
 *   所以 "Zebra" 会排在 "apple" 前面。本题测试数据都是小写。
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100

/* 判断单词里有没有元音 */
int has_vowel(char *w)
{
    // TODO
    return 0;
}

/* 找出不含元音的单词，按字典序排好存进 res，返回个数 */
int FindNoVowel(char *str[], int num, char res[][20])
{
    // TODO
    return 0;
}

int main(void)
{
    int num;
    char buf[MAXN][20];             /* 存输入的单词 */
    char *str[MAXN];                /* 指针数组，指向 buf 的各行 */
    char res[MAXN][20];             /* 结果 */

    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%s", buf[i]);
        str[i] = buf[i];            /* 指针指向对应的行 */
    }

    int m = FindNoVowel(str, num, res);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%s\n", res[i]);
    }

    return 0;
}
