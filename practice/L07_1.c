/*
 * L07_1 · 用函数计算定积分（带菜单）
 *
 * 【题目】（经典题）
 *   写一个程序，用数值方法计算函数 f(x) = cos(x) 在区间 [0, 1] 上的定积分。
 *   要求提供菜单，让用户选择方法：
 *
 *       1. 梯形法
 *       2. 矩形法（中点法）
 *       0. 退出
 *
 *   输入格式：先输入方法编号，再输入等分数 n。（选 0 直接退出）
 *
 * 【输入格式示例】
 *   1 10
 *   （表示：用梯形法，等分 10 份）
 *
 * 【输出格式】
 *   一个浮点数，保留 8 位小数，占一行。
 *   注意：选 0 退出时不输出任何东西。
 *
 * 【样例】
 *   输入 1 10      →  0.84076964
 *   输入 2 10      →  0.84182170
 *   输入 1 1000    →  0.84147091
 *   输入 0 0       →  （无输出）
 *
 * 【参考真值】
 *   ∫₀¹ cos(x) dx = sin(1) - sin(0) = 0.84147098...
 *   等分越多越接近。n=1000 时梯形法已经精确到 8 位小数了。
 *
 * 【两种数值方法的原理】
 *
 *   把 [a, b] 分成 n 段，每段宽 h = (b-a)/n。
 *
 *   梯形法：每一段用一个梯形近似，面积 = (左高 + 右高) / 2 × h
 *           把所有梯形的面积加起来。
 *           第一个和最后一个点只出现一次，中间的点左右各用到一次。
 *
 *   中点法（矩形法）：每一段用一个矩形近似，高度取该段【中点】的函数值。
 *           面积 = f(中点) × h，把所有矩形加起来。
 *
 * 【代码框架（已经帮你写好了）】
 *
 *       double f(double x)                    (被积函数)
 *       {
 *           return cos(x);
 *       }
 *
 *       double trapezoid(double a, double b, int n)   (梯形法)
 *       {
 *           double h = (b - a) / n;
 *           double s = (f(a) + f(b)) / 2.0;           (两端点各算半次)
 *           for (int i = 1; i < n; i++) {
 *               s = s + f(a + i * h);
 *           }
 *           return s * h;
 *       }
 *
 *       double midpoint(double a, double b, int n)    (中点法)
 *       {
 *           double h = (b - a) / n;
 *           double s = 0;
 *           for (int i = 0; i < n; i++) {
 *               s = s + f(a + (i + 0.5) * h);         (注意那个 0.5)
 *           }
 *           return s * h;
 *       }
 *
 * 【你要做的】
 *   1. 把上面三个函数的 TODO 补完
 *   2. 在 main 里写菜单逻辑
 *
 * 【⚠️ 梯形法为什么两端点要除以 2】
 *   把每个小梯形的面积 (f(x_i) + f(x_{i+1})) / 2 * h 全部展开：
 *       = h/2 * [f(x0) + f(x1) + f(x1) + f(x2) + ... + f(x_{n-1}) + f(x_n)]
 *   可以看到中间的每个点都出现两次，只有两端的 f(x0) 和 f(x_n) 出现一次。
 *   所以可以写成 h * [ (f(a)+f(b))/2 + f(x1)+...+f(x_{n-1}) ]
 *   这就是上面代码里 s 初始值的来源。
 *   这样写比每段单独算梯形少一半计算量，结果完全一样。
 */

#include <stdio.h>
#include <math.h>

/* 被积函数 f(x) = cos(x) */
double f(double x)
{
    // TODO
    return 0.0;
}

/* 梯形法 */
double trapezoid(double a, double b, int n)
{
    // TODO
    return 0.0;
}

/* 中点法（矩形法） */
double midpoint(double a, double b, int n)
{
    // TODO
    return 0.0;
}

int main(void)
{
    int choice, n;

    scanf("%d %d", &choice, &n);

    // TODO: 根据 choice 调用对应的函数并输出结果
    //       choice 是 0 时什么都不输出

    return 0;
}
