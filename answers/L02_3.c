/* L02_3 参考答案 · 各位数字之和 */

#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0;

    scanf("%d", &n);

    /* 题目限定输入在 0~1000，最多 4 位，所以手工拆四次就够 */
    sum = n % 10             /* 个位 */
        + n / 10 % 10        /* 十位 */
        + n / 100 % 10       /* 百位 */
        + n / 1000;          /* 千位 */

    printf("%d\n", sum);

    return 0;
}
