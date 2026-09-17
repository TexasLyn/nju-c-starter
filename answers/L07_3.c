/* L07_3 参考答案 · 哥德巴赫猜想验证 */

#include <stdio.h>

int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    for (int n = 6; n <= 50; n = n + 2) {
        for (int p = 2; p <= n / 2; p++) {
            if (is_prime(p) && is_prime(n - p)) {
                printf("%d=%d+%d\n", n, p, n - p);
                break;              /* 只要第一组，p 最小 */
            }
        }
    }

    return 0;
}
