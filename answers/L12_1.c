/* L12_1 参考答案 · 找最长单词 */

#include <stdio.h>
#include <string.h>

int is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void)
{
    char s[201];
    int bestLen = 0;
    int bestStart = 0;

    fgets(s, 201, stdin);
    s[strcspn(s, "\n")] = '\0';

    int n = (int)strlen(s);
    int i = 0;

    while (i < n) {
        /* 跳过非字母 */
        while (i < n && !is_letter(s[i])) {
            i++;
        }

        int start = i;

        /* 走到单词结尾 */
        while (i < n && is_letter(s[i])) {
            i++;
        }

        int len = i - start;

        /* 用 > 而不是 >= ：同样长时保留先出现的 */
        if (len > bestLen) {
            bestLen = len;
            bestStart = start;
        }
    }

    for (int k = 0; k < bestLen; k++) {
        printf("%c", s[bestStart + k]);
    }
    printf("\n");

    return 0;
}
