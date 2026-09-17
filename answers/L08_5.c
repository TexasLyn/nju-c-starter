/* L08_5 参考答案 · 指针参数的写法和调用 */

#include <stdio.h>

void set_values(int *a, int *b)
{
    *a = 10;            /* 加 * 才是修改指向的变量 */
    *b = 20;
}

int main(void)
{
    int x, y;

    set_values(&x, &y);     /* 传地址 */

    printf("%d %d\n", x, y);

    return 0;
}
