/*
 * L04_1 · 一元二次方程求实根
 *
 * 【题目】（经典题）
 *   读入系数 a、b、c，求解方程 ax² + bx + c = 0 的实根。
 *
 * 【输入格式】
 *   三个浮点数，用空格分隔。
 *
 * 【输出格式】
 *   分三种情况：
 *     - 判别式 > 0：两个不同的实根，按【从小到大】输出，各保留 2 位小数
 *                   格式：x1=较小值 x2=较大值
 *     - 判别式 == 0：一个实根
 *                   格式：x=值
 *     - 判别式 < 0：没有实根
 *                   格式：No real root
 *
 * 【样例】
 *   输入 1 -5 6    →  x1=2.00 x2=3.00
 *   输入 1 -2 1    →  x=1.00
 *   输入 1 2 3     →  No real root
 *
 * 【求根公式】
 *   判别式 delta = b² - 4ac
 *   delta > 0 时：x = (-b ± √delta) / (2a)
 *   delta == 0 时：x = -b / (2a)
 *
 * 【提示】
 *   - b² 写成 b*b，C 里没有 ^ 这个乘方运算符
 *   - 开方用 sqrt()，要 #include <math.h>
 *   - 两个根要从小到大输出，所以要比较大小后再打印
 *   - 浮点数判断相等（delta == 0）严格来说应该用 fabs，但这题用 == 也能过，
 *     因为输入都是整数，delta 恰好是 0 的时候能精确表示
 *
 * 【常见错误】
 *   把 -b + sqrt(delta) 和 -b - sqrt(delta) 直接输出。
 *   因为 a 可能是负数，sqrt(delta) 前面是加号的那个不一定是较大的根。
 *   所以要先算出来再比大小。
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    // TODO 1: 算判别式 delta

    // TODO 2: 用 if / else if / else 分三种情况输出

    return 0;
}
