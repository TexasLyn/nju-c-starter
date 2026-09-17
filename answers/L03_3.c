/* L03_3 参考答案 · 海伦公式 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("%.6f\n", area);

    return 0;
}
