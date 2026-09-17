/*
 * L03_1 · 分离一个浮点数的符号、整数部分、小数部分
 *
 * 【题目】（经典题）
 *   读入一个非 0 的浮点数，输出它的符号、整数部分、小数部分。
 *
 * 【输入格式】
 *   一个非 0 的浮点数，例如 -123.456
 *
 * 【输出格式】
 *   三行，格式必须完全一致（注意冒号是英文冒号，行尾不要多空格）：
 *
 *   Sign:-
 *   Integral part:123
 *   Decimal fraction part:0.456000
 *
 *   第三行保留 6 位小数。
 *
 * 【提示】
 *   三个步骤：
 *
 *   1. 符号：判断 x 是不是小于 0。
 *         if (x < 0) printf("Sign:-\n");
 *         else       printf("Sign:+\n");
 *
 *   2. 整数部分：先把 x 变成正数，再砍掉小数。
 *         double a = fabs(x);        // 绝对值，需要 #include <math.h>
 *         int ip = (int)a;           // (int) 是强制类型转换，把小数砍掉
 *         printf("Integral part:%d\n", ip);
 *
 *   3. 小数部分 = 正数 - 整数部分。
 *         double dp = a - ip;
 *         printf("Decimal fraction part:%.6f\n", dp);
 *
 * 【为什么整数部分不能直接用 (int)x】
 *   因为 (int)(-123.456) 得到的是 -123，负数。题目要求输出 123，
 *   所以要先取绝对值。
 *
 * 【注意】
 *   小数部分用 %f 打印时可能有极小的误差（比如 0.456000000000003），
 *   但 %.6f 会把误差藏在第 6 位之后，所以看起来是干净的 0.456000。
 *   这就是为什么浮点数输出一定要限制小数位数。
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    scanf("%lf", &x);

    // TODO 1: 输出符号（Sign:+ 或 Sign:-）

    // TODO 2: 输出整数部分（Integral part:数字）

    // TODO 3: 输出小数部分（Decimal fraction part:保留6位小数）

    return 0;
}
