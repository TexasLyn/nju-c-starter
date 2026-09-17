/* L06_5 参考答案 · 二分法 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double lo = -1.0, hi = 1.0;
    int iter = 0;

    while (hi - lo > 1e-6 && iter < 200) {
        double mid = (lo + hi) / 2;

        if (exp(mid) + mid > 0) {
            hi = mid;
        } else {
            lo = mid;
        }
        iter++;
    }

    printf("%.6f\n", (lo + hi) / 2);

    return 0;
}
