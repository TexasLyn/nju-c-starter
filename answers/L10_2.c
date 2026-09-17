/* L10_2 参考答案 · 原地删除重复数据 */

#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;
    int a[MAXN];
    int k = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int seen = 0;

        for (int j = 0; j < k; j++) {       /* 只在已保留的数据里找 */
            if (a[j] == a[i]) {
                seen = 1;
                break;
            }
        }

        if (!seen) {
            a[k] = a[i];                    /* 先写 */
            k++;                            /* 再前进 */
        }
    }

    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%d", a[i]);
        if (i < k - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
