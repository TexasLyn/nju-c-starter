/* L10_5 参考答案 · 数组越界 */

#include <stdio.h>

#define N 5

int main(void)
{
    int a[N];
    int sum = 0;

    for (int i = 0; i < N; i++) {       /* 原来是 <= N，越界了 */
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i++) {
        sum = sum + a[i];
    }

    printf("%d\n", sum);

    return 0;
}
