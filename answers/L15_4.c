/* L15_4 参考答案 · gcd + 数位拆分 + 写文件 */

#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void)
{
    int a, b;
    int g;
    int s1 = 0, s2 = 0;
    int t;

    scanf("%d %d", &a, &b);

    g = gcd(a, b);

    t = g;
    while (t > 0) {
        int d = t % 10;

        if (d % 3 == 0 || d % 5 == 0) {
            s1 = s1 + d;
        } else {
            s2 = s2 + d;
        }

        t = t / 10;
    }

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "%d\n", g);
    fprintf(fp, "%d %d\n", s1, s2);
    fclose(fp);

    printf("%d\n", g);
    printf("%d %d\n", s1, s2);

    return 0;
}
