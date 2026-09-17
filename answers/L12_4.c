/* L12_4 参考答案 · 不含元音的单词 + 字典序排序 */

#include <stdio.h>
#include <string.h>

#define MAXN 100

int has_vowel(char *w)
{
    for (int i = 0; w[i] != '\0'; i++) {
        char c = w[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return 1;
        }
    }

    return 0;
}

int FindNoVowel(char *str[], int num, char res[][20])
{
    int m = 0;

    /* 第一步：收集不含元音的单词 */
    for (int i = 0; i < num; i++) {
        if (!has_vowel(str[i])) {
            strcpy(res[m], str[i]);
            m++;
        }
    }

    /* 第二步：整行按字典序排序 */
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (strcmp(res[i], res[j]) > 0) {
                char t[20];
                strcpy(t, res[i]);
                strcpy(res[i], res[j]);
                strcpy(res[j], t);
            }
        }
    }

    return m;
}

int main(void)
{
    int num;
    char buf[MAXN][20];
    char *str[MAXN];
    char res[MAXN][20];

    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%s", buf[i]);
        str[i] = buf[i];
    }

    int m = FindNoVowel(str, num, res);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%s\n", res[i]);
    }

    return 0;
}
