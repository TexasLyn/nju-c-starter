/* L12_2 参考答案 · 子串替换 */

#include <stdio.h>
#include <string.h>

int replace_str(char *s, char *t, char *g)
{
    char buf[2048];
    int cnt = 0;
    int tl = (int)strlen(t);
    char *p = s;

    buf[0] = '\0';                  /* 必须先置空，strcat 才有落脚点 */

    while (*p != '\0') {
        if (strncmp(p, t, tl) == 0) {
            strcat(buf, g);         /* 匹配：接上替换串 */
            p = p + tl;             /* 跳过整个 t */
            cnt++;
        } else {
            int l = (int)strlen(buf);
            buf[l] = *p;            /* 不匹配：把这个字符接上去 */
            buf[l + 1] = '\0';      /* 手动维护结尾的 \0 */
            p++;
        }
    }

    strcpy(s, buf);
    return cnt;
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
