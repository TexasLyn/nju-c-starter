/* L14_1 参考答案 · 反序素数写入文件（上机常见题型） */

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

int reverse_num(int n)
{
    int r = 0;

    while (n > 0) {
        r = r * 10 + n % 10;
        n = n / 10;
    }

    return r;
}

int rev_prime(int m, int n, int x[])
{
    int k = 0;

    for (int i = m; i <= n; i++) {
        if (is_prime(i) && is_prime(reverse_num(i))) {
            x[k] = i;
            k++;
        }
    }

    return k;
}

int main(void)
{
    int m, n;
    int x[1000];
    int k;

    scanf("%d %d", &m, &n);

    k = rev_prime(m, n, x);

    /* ---- 写入文件 ---- */
    FILE *fp = fopen("out.txt", "w");

    if (fp == NULL) {
        printf("无法创建 out.txt\n");
        return 1;
    }

    fprintf(fp, "%d\n", k);

    for (int i = 0; i < k; i++) {
        if (i > 0) {
            fprintf(fp, " ");
        }
        fprintf(fp, "%d", x[i]);
    }
    fprintf(fp, "\n");

    fclose(fp);

    /* ---- 同时打印到屏幕 ---- */
    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", x[i]);
    }
    printf("\n");

    return 0;
}
