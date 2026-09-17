/* L05_3 参考答案 · 分解质因数 */

#include <stdio.h>

int main(void)
{
    int n;
    int original;

    scanf("%d", &n);
    original = n;

    printf("%d=", original);

    int first = 1;
    for (int p = 2; p <= n; p++) {
        while (n % p == 0) {
            if (!first) {
                printf("*");
            }
            printf("%d", p);
            first = 0;
            n = n / p;
        }
    }

    printf("\n");

    return 0;
}
