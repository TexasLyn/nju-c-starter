/* L12_5 参考答案 · 字符串比较 */

#include <stdio.h>
#include <string.h>             /* 原来的程序漏了这个 */

int main(void)
{
    char a[100], b[100];

    scanf("%s", a);
    scanf("%s", b);

    /* 比较字符串必须用 strcmp，不能用 == */
    if (strcmp(a, b) == 0) {
        printf("same\n");
    } else {
        printf("different\n");
    }

    return 0;
}
