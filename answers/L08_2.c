/* L08_2 参考答案 · 局部变量遮蔽 */

#include <stdio.h>

int g = 100;                    /* 全局变量 */

void f(void)
{
    int g = 200;                /* 局部变量，遮蔽全局的 g */
    g = g + 1;
    printf("f: %d\n", g);
}

void h(void)
{
    g = g + 1;                  /* 没有 int，改的是全局 g */
    printf("h: %d\n", g);
}

int main(void)
{
    int x = 1;

    {
        int x = 10;             /* 内层 x，遮蔽外层 */
        x = x + 5;
        printf("inner: %d\n", x);
    }

    printf("outer: %d\n", x);

    f();
    h();
    printf("global: %d\n", g);

    return 0;
}
