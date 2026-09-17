/* L09_3 参考答案 · 返回 static 变量的地址 */

#include <stdio.h>

int *count(char *ch)
{
    static int n = 0;           /* 必须 static，否则返回的是悬空指针 */

    (void)ch;                   /* 本题用不到这个参数，这样写可以消掉"未使用"警告 */

    n++;
    return &n;
}

int main(void)
{
    int *p;

    p = count("a");
    printf("%d\n", *p);

    p = count("b");
    printf("%d\n", *p);

    p = count("c");
    printf("%d\n", *p);

    return 0;
}
