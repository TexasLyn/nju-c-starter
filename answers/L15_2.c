/* L15_2 参考答案 · 逗号分隔数字串转 int 数组
 *
 * 3 处错误的修正：
 *   1. int parse(char *s, int a)   →  int parse(char *s, int a[])
 *   2. cur * 10 + s[i]             →  cur * 10 + (s[i] - '0')
 *   3. a[0] = cur                  →  a[n] = cur
 */

#include <stdio.h>
#include <string.h>

int parse(char *s, int a[])
{
    int n = 0;
    int cur = 0;
    int len = (int)strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cur = cur * 10 + (s[i] - '0');      /* 字符转数字 */
        } else if (s[i] == ',') {
            a[n] = cur;
            n++;
            cur = 0;
        }
    }

    /* 最后一个数后面没有逗号，要单独存 */
    a[n] = cur;
    n++;

    return n;
}

int main(void)
{
    char s[400];
    int a[100];
    int n;

    scanf("%s", s);

    n = parse(s, a);

    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
