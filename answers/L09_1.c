/* L09_1 参考答案 · 复数四则运算（全局变量） */

#include <stdio.h>

double re, im;                  /* 全局变量存结果 */

void cfun(char op, double a, double b, double c, double d)
{
    switch (op) {
    case '+':
        re = a + c;
        im = b + d;
        break;
    case '-':
        re = a - c;
        im = b - d;
        break;
    case '*':
        re = a * c - b * d;
        im = a * d + b * c;
        break;
    case '/':
        re = (a * c + b * d) / (c * c + d * d);
        im = (b * c - a * d) / (c * c + d * d);
        break;
    default:
        break;
    }
}

int main(void)
{
    char op;
    double a, b, c, d;

    scanf(" %c %lf %lf %lf %lf", &op, &a, &b, &c, &d);

    cfun(op, a, b, c, d);

    printf("%.6f %.6f\n", re, im);

    return 0;
}
