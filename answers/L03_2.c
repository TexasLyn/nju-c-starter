/* L03_2 参考答案 · math.h 函数练习 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    double x, y;

    scanf("%lf %lf", &x, &y);

    double rad = x * PI / 180.0;    /* 角度转弧度 */

    printf("sin=%.6f\n", sin(rad));
    printf("cos=%.6f\n", cos(rad));
    printf("abs=%.6f\n", fabs(x));
    printf("exp=%.6f\n", exp(x));
    printf("pow=%.6f\n", pow(x, y));

    return 0;
}
