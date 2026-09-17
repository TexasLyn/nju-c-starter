/* L04_1 参考答案 · 一元二次方程求实根 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double r1 = (-b - sqrt(delta)) / (2 * a);
        double r2 = (-b + sqrt(delta)) / (2 * a);
        double lo, hi;

        /* a 可能是负数，所以不能想当然认为 r1 小 r2 大，要真的比一下 */
        if (r1 < r2) {
            lo = r1;
            hi = r2;
        } else {
            lo = r2;
            hi = r1;
        }

        printf("x1=%.2f x2=%.2f\n", lo, hi);
    } else if (delta == 0) {
        printf("x=%.2f\n", -b / (2 * a));
    } else {
        printf("No real root\n");
    }

    return 0;
}
