/* L11_1 参考答案 · 4×4 左下三角素数处理 */

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

int next_prime(int n)
{
    int p = n + 1;              /* 从 n+1 开始找，比 n 大的最小素数 */

    while (!is_prime(p)) {
        p++;
    }

    return p;
}

int main(void)
{
    int a[4][4];
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    /* 左下三角（含对角线）：第 i 行只处理 j = 0..i */
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            if (is_prime(a[i][j])) {
                a[i][j] = next_prime(a[i][j]);
                count++;
            } else {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", a[i][j]);
            if (j < 3) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("%d\n", count);

    return 0;
}
