/* L10_4 参考答案 · 素数首尾交换 */

#include <stdio.h>

#define MAXN 100

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
    int n;
    int a[MAXN];
    int pos[MAXN];
    int m = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* 收集素数的位置 */
    for (int i = 0; i < n; i++) {
        if (is_prime(a[i])) {
            pos[m] = i;
            m++;
        }
    }

    /* 按位置首尾配对交换 */
    for (int i = 0; i < m / 2; i++) {
        int t = a[pos[i]];
        a[pos[i]] = a[pos[m - 1 - i]];
        a[pos[m - 1 - i]] = t;
    }

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
