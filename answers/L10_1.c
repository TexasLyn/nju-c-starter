/* L10_1 参考答案 · 统计不相同的数据个数 */

#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;
    int a[MAXN];
    int count = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int seen = 0;

        for (int j = 0; j < i; j++) {       /* 只看 i 前面的 */
            if (a[j] == a[i]) {
                seen = 1;
                break;
            }
        }

        if (!seen) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
