/* L07_2 参考答案 · 回文数 + 孪生素数 */

#include <stdio.h>

int huiwen(long n)
{
    long rev = 0;
    long t = n;

    while (t > 0) {
        rev = rev * 10 + t % 10;
        t = t / 10;
    }

    return rev == n;
}

int prime(int n)
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
    int m;
    int cntHui = 0;
    int cntTwin = 0;

    scanf("%d", &m);

    for (long i = 1; i <= m; i++) {
        if (huiwen(i)) {
            cntHui++;
        }
    }

    for (int i = 1; i + 2 <= m; i++) {
        if (prime(i) && prime(i + 2)) {
            cntTwin++;
        }
    }

    printf("%d\n%d\n", cntHui, cntTwin);

    return 0;
}
