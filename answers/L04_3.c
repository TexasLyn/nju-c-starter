/* L04_3 参考答案 · 奖金提成（if 和 switch 各一遍） */

#include <stdio.h>

int main(void)
{
    long p;
    long bonus1 = 0;
    long bonus2 = 0;

    scanf("%ld", &p);

    /* ---- 第一种：if / else if，从高到低判断 ---- */
    if (p > 1000000) {
        bonus1 = 39500 + (p - 1000000) * 0.01;
    } else if (p > 600000) {
        bonus1 = 33500 + (p - 600000) * 0.015;
    } else if (p > 400000) {
        bonus1 = 27500 + (p - 400000) * 0.03;
    } else if (p > 200000) {
        bonus1 = 17500 + (p - 200000) * 0.05;
    } else if (p > 100000) {
        bonus1 = 10000 + (p - 100000) * 0.075;
    } else {
        bonus1 = p * 0.10;
    }

    /* ---- 第二种：switch，靠整除把范围压缩成整数 ---- */
    switch (p / 100000) {
    case 0:
        bonus2 = p * 0.10;
        break;
    case 1:
        bonus2 = 10000 + (p - 100000) * 0.075;
        break;
    case 2:
    case 3:                                  /* 2 和 3 故意穿透，共用一段代码 */
        bonus2 = 17500 + (p - 200000) * 0.05;
        break;
    case 4:
    case 5:
        bonus2 = 27500 + (p - 400000) * 0.03;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        bonus2 = 33500 + (p - 600000) * 0.015;
        break;
    default:                                 /* p >= 1000000 */
        bonus2 = 39500 + (p - 1000000) * 0.01;
        break;
    }

    printf("%ld %ld\n", bonus1, bonus2);

    return 0;
}
