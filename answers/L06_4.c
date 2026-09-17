/* L06_4 参考答案 · 牛顿迭代法 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    int iter = 0;

    while (1) {
        double f = cos(x) - x;
        double df = -sin(x) - 1;
        double nx = x - f / df;

        iter++;
        if (fabs(nx - x) < 1e-6 || iter > 100) {
            x = nx;
            break;
        }
        x = nx;
    }

    printf("%.6f\n", x);

    return 0;
}
