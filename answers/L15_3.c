/* L15_3 参考答案 · 结构体数组按条件筛选
 *
 * 4 处错误的修正：
 *   1. } W        →  } W;                （结构体定义末尾要有分号）
 *   2. 缺 #include <string.h>            （strcmp 需要）
 *   3. strcmp(...) = 0  →  == 0          （= 是赋值）
 *   4. res[0] = s[i]    →  res[m] = s[i] （下标要用 m）
 */

#include <stdio.h>
#include <string.h>             /* 原来漏了这个 */

typedef struct {
    int  id;
    char name[20];
    int  salary;
} W;                            /* 原来漏了分号 */

int sift(W s[], int n, char cond[], W res[])
{
    int m = 0;

    for (int i = 0; i < n; i++) {
        int keep = 0;

        if (strcmp(cond, "gt2000") == 0) {      /* 原来是 = 0 */
            if (s[i].salary > 2000) {
                keep = 1;
            }
        } else if (strcmp(cond, "lt3000") == 0) {
            if (s[i].salary < 3000) {
                keep = 1;
            }
        } else {
            keep = 1;
        }

        if (keep) {
            res[m] = s[i];                      /* 原来是 res[0] */
            m++;
        }
    }

    return m;
}

int main(void)
{
    W s[100];
    W res[100];
    int n;
    char cond[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &s[i].id, s[i].name, &s[i].salary);
    }

    scanf("%s", cond);

    int m = sift(s, n, cond, res);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d %s %d\n", res[i].id, res[i].name, res[i].salary);
    }

    return 0;
}
