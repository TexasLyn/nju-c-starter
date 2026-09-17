/* L01_2 参考答案 · 输入 x，求 y = x*x + 2*x - 10 */

#include <stdio.h>

int main(void)
{
    int x;
    int y = 0;

    scanf("%d", &x);

    y = x * x + 2 * x - 10;

    printf("%d\n", y);

    return 0;
}
