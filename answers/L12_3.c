/* L12_3 参考答案 · 过滤合法标识符 */

#include <stdio.h>
#include <string.h>

int is_valid(char *s)
{
    if (s[0] == '\0') {
        return 0;                           /* 空串不合法 */
    }
    if (s[0] >= '0' && s[0] <= '9') {
        return 0;                           /* 数字开头不合法 */
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        int ok = (c >= 'a' && c <= 'z')
              || (c >= 'A' && c <= 'Z')
              || (c >= '0' && c <= '9')
              || (c == '_');

        if (!ok) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char s[100];

    while (fgets(s, 100, stdin) != NULL) {
        s[strcspn(s, "\n")] = '\0';

        if (strcmp(s, "END") == 0) {
            break;
        }

        if (is_valid(s)) {
            printf("%s\n", s);
        }
    }

    return 0;
}
