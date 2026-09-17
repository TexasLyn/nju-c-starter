/* L10_3 参考答案 · 用两个数组统计各数据出现次数 */

#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;
    int a[MAXN];
    int val[MAXN];
    int cnt[MAXN];
    int m = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (val[j] == a[i]) {
                cnt[j]++;
                break;
            }
        }

        /* j == m 说明内层循环自然结束，没 break，也就是没找到 */
        if (j == m) {
            val[m] = a[i];
            cnt[m] = 1;
            m++;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d %d\n", val[i], cnt[i]);
    }

    return 0;
}
