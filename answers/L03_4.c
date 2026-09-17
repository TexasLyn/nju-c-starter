/* L03_4 参考答案 · 不同精度输出 */

#include <stdio.h>

int main(void)
{
    double x;

    scanf("%lf", &x);

    printf("%.1f\n", x);
    printf("%.2f\n", x);
    printf("%.3f\n", x);
    printf("%.4f\n", x);

    return 0;
}
