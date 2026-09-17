/* L09_4 参考答案 · 函数指针求定积分 */

#include <stdio.h>
#include <math.h>

double f_cos(double x)
{
    return cos(x);
}

double f_sin(double x)
{
    return sin(x);
}

double f_linear(double x)
{
    return 2 * x + 1;
}

double integral(double a, double b, long n, double (*f)(double))
{
    double h = (b - a) / n;
    double s = 0;

    for (long i = 0; i < n; i++) {
        s = s + f(a + (i + 0.5) * h);
    }

    return s * h;
}

int main(void)
{
    printf("cos=%.8f\n", integral(0.0, 1.0, 1000, f_cos));
    printf("sin=%.8f\n", integral(0.0, 1.0, 1000, f_sin));
    printf("linear=%.8f\n", integral(0.0, 1.0, 1000, f_linear));

    return 0;
}
