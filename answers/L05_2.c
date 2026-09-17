/* L05_2 参考答案 · 三位数黑洞数 495 */

#include <stdio.h>

int main(void)
{
    int n;
    int steps = 0;

    scanf("%d", &n);

    while (n != 495) {
        int d1 = n / 100;
        int d2 = n / 10 % 10;
        int d3 = n % 10;
        int t;

        /* 三个数排序：排完 d1 <= d2 <= d3 */
        if (d1 > d2) { t = d1; d1 = d2; d2 = t; }
        if (d1 > d3) { t = d1; d1 = d3; d3 = t; }
        if (d2 > d3) { t = d2; d2 = d3; d3 = t; }

        int max = d3 * 100 + d2 * 10 + d1;
        int min = d1 * 100 + d2 * 10 + d3;

        n = max - min;
        steps++;
    }

    printf("%d\n", steps);

    return 0;
}
