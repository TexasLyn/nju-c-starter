/* L15_5 参考答案 · 最后一个素数 + 局部选择排序 + 写文件 */

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

int main(void)
{
    int n;
    int a[1000];
    int pos = -1;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* 从后往前找第一个素数，就是最后一个素数 */
    for (int i = n - 1; i >= 0; i--) {
        if (is_prime(a[i])) {
            pos = i;
            break;
        }
    }

    /* 只对 pos 之前的元素排序（两个上界都是 pos） */
    if (pos > 0) {
        for (int i = 0; i < pos; i++) {
            for (int j = i + 1; j < pos; j++) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    if (pos == -1) {
        fprintf(fp, "none\n");
        printf("none\n");
    } else {
        fprintf(fp, "%d\n", pos);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                fprintf(fp, " ");
            }
            fprintf(fp, "%d", a[i]);
        }
        fprintf(fp, "\n");

        printf("%d\n", pos);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", a[i]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
