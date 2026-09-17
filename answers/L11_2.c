/* L11_2 参考答案 · 多集合求交集 */

#include <stdio.h>

#define MAXK 10
#define MAXC 100

int main(void)
{
    int k;
    int set[MAXK][MAXC];
    int len[MAXK];
    int res[MAXC];
    int m = 0;

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; j++) {
            scanf("%d", &set[i][j]);
        }
    }

    /* 拿第 0 个集合的每个元素，去其余集合里查 */
    for (int j = 0; j < len[0]; j++) {
        int x = set[0][j];
        int inAll = 1;

        for (int i = 1; i < k; i++) {
            int found = 0;

            for (int t = 0; t < len[i]; t++) {
                if (set[i][t] == x) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                inAll = 0;
                break;
            }
        }

        if (inAll) {
            /* 避免重复收集（第一个集合自己可能有重复元素） */
            int dup = 0;
            for (int t = 0; t < m; t++) {
                if (res[t] == x) {
                    dup = 1;
                    break;
                }
            }
            if (!dup) {
                res[m] = x;
                m++;
            }
        }
    }

    /* 选择排序 */
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (res[i] > res[j]) {
                int t = res[i];
                res[i] = res[j];
                res[j] = t;
            }
        }
    }

    if (m == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < m; i++) {
            printf("%d", res[i]);
            if (i < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
