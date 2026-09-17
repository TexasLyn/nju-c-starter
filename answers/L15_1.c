/* L15_1 参考答案 · 提取以 e 结尾的单词
 *
 * 4 处错误的修正：
 *   1. char words[][]      →  char words[][20]      （列数必须写死）
 *   2. int wlen = i-start+1 →  int wlen = i - start  （长度算多了一个）
 *   3. s[i] == 'e'          →  s[i-1] == 'e'         （i 停在单词后一格）
 *   4. words[n][wlen] = 'x' →  words[n][wlen] = '\0' （必须补结束符）
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100

int is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int find_e_words(char *s, char words[][20])
{
    int n = 0;
    int i = 0;
    int len = (int)strlen(s);

    while (i < len) {
        while (i < len && !is_letter(s[i])) {
            i++;
        }

        int start = i;

        while (i < len && is_letter(s[i])) {
            i++;
        }

        int wlen = i - start;

        if (wlen > 0 && s[i - 1] == 'e') {
            for (int k = 0; k < wlen; k++) {
                words[n][k] = s[start + k];
            }
            words[n][wlen] = '\0';
            n++;
        }
    }

    return n;
}

int main(void)
{
    char s[400];
    char words[MAXN][20];
    int n;

    fgets(s, 400, stdin);
    s[strcspn(s, "\n")] = '\0';

    n = find_e_words(s, words);

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
