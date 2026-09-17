/* L07_1 参考答案 · 数值积分（梯形法 / 中点法） */

#include <stdio.h>
#include <math.h>

/* 被积函数 */
double f(double x)
{
    return cos(x);
}

/* 梯形法 */
double trapezoid(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = (f(a) + f(b)) / 2.0;      /* 两端点各算半次 */

    for (int i = 1; i < n; i++) {
        s = s + f(a + i * h);
    }

    return s * h;
}

/* 中点法（矩形法） */
double midpoint(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = 0;

    for (int i = 0; i < n; i++) {
        s = s + f(a + (i + 0.5) * h);    /* 取每段中点 */
    }

    return s * h;
}

int main(void)
{
    int choice, n;

    scanf("%d %d", &choice, &n);

    if (choice == 1) {
        printf("%.8f\n", trapezoid(0.0, 1.0, n));
    } else if (choice == 2) {
        printf("%.8f\n", midpoint(0.0, 1.0, n));
    }
    /* choice == 0 时什么都不输出 */

    return 0;
}
