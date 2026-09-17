/* L14_3 参考答案 · 数字子串前插入 '-' */

#include <stdio.h>
#include <string.h>

char *insert(char *p)
{
    char buf[1024];
    int k = 0;

    for (int i = 0; p[i] != '\0'; i++) {
        int isDigit = (p[i] >= '0' && p[i] <= '9');

        /* i > 0 的短路保护：i == 0 时不会去读 p[-1] */
        int prevIsDigit = (i > 0 && p[i - 1] >= '0' && p[i - 1] <= '9');

        if (isDigit && !prevIsDigit) {      /* 数字子串的开头 */
            buf[k] = '-';
            k++;
        }

        buf[k] = p[i];
        k++;
    }

    buf[k] = '\0';

    strcpy(p, buf);
    return p;
}

int main(void)
{
    char s[400];

    fgets(s, 400, stdin);
    s[strcspn(s, "\n")] = '\0';

    insert(s);

    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("无法创建 data.txt\n");
        return 1;
    }

    fprintf(fp, "%s\n", s);
    fclose(fp);

    printf("%s\n", s);

    return 0;
}
