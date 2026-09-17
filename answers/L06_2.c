/* L06_2 参考答案 · sin 幂级数递推 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    scanf("%lf", &x);

    double term = x;
    double sum = x;
    int k = 0;

    while (fabs(term) >= 1e-8) {
        term = -term * x * x / ((2 * k + 2) * (2 * k + 3));
        sum = sum + term;
        k++;
    }

    printf("%.8f\n", sum);

    return 0;
}
