/*
 * L09_4 · 函数指针求定积分（经典题）
 *
 * 【题目】
 *   写一个通用的定积分函数，第四个参数是【函数指针】：
 *
 *       double integral(double a, double b, long n, double (*f)(double))
 *
 *   用它分别计算下面三个函数在 [0, 1] 上的定积分（用中点法，n = 1000）：
 *
 *       f1(x) = cos(x)
 *       f2(x) = sin(x)
 *       f3(x) = 2x + 1
 *
 * 【输出格式】
 *   三行，每行格式 "名称=值"，值保留 8 位小数：
 *
 *   cos=0.84147102
 *   sin=0.45969771
 *   linear=2.00000000
 *
 * 【函数指针的写法（本课核心）】
 *
 *       double (*f)(double)
 *         ↑   ↑   ↑
 *         │   │   └── 这个函数接受一个 double 参数
 *         │   └────── f 是一个指针
 *         └────────── f 指向的函数返回 double
 *
 * 【⚠️ 括号绝对不能省】
 *       double (*f)(double)     (✓ f 是"函数指针")
 *       double *f(double)       (✗ 这是"函数 f，返回 double*" —— 完全不同的东西)
 *
 *   原因：() 的优先级比 * 高。不加括号时，编译器先看到 f(double)，
 *   就把 f 当成函数了。必须用 (*f) 强制先绑定 *。
 *
 * 【怎么用这个参数 f】
 *   在函数体里，把 f 当成普通函数名来用：
 *
 *       double integral(double a, double b, long n, double (*f)(double))
 *       {
 *           double h = (b - a) / n;
 *           double s = 0;
 *
 *           for (long i = 0; i < n; i++) {
 *               s = s + f(a + (i + 0.5) * h);      (← 直接 f(值))
 *           }
 *
 *           return s * h;
 *       }
 *
 * 【怎么把函数传进来（⚠️ 最容易错的地方）】
 *
 *       integral(0, 1, 1000, f_cos)        (✓ 只写函数名，不带括号)
 *       integral(0, 1, 1000, f_cos(1.0))   (✗ 带括号 = 先调用，传的是结果)
 *
 *   在 C 里，函数名本身就代表函数的地址（就像数组名代表首地址）。
 *   所以写 f_cos 和写 &f_cos 效果一样，写 f_cos 更常见。
 *
 *   【不带括号】传的是"这个函数"
 *   【带括号】传的是"调用它的返回值"
 *   这两个完全不同，一定要分清。
 *
 * 【三个被积函数怎么写】
 *   普通的函数定义就行，不需要特殊写法：
 *
 *       double f_cos(double x)    { return cos(x); }
 *       double f_sin(double x)    { return sin(x); }
 *       double f_linear(double x) { return 2 * x + 1; }
 *
 * 【中点法公式】
 *   把 [a, b] 分成 n 段，每段宽 h = (b-a)/n。
 *   每段用一个矩形近似，高度取该段【中点】的函数值：
 *       面积 = f(中点) × h
 *   全部加起来就是积分近似值。
 *
 *   注意 (i + 0.5) 那个 0.5 —— 这是取中点，不是取左端点。
 *
 * 【参考真值】
 *   ∫₀¹ cos(x)dx = sin(1) ≈ 0.8414709848
 *   ∫₀¹ sin(x)dx = 1 - cos(1) ≈ 0.4596976941
 *   ∫₀¹ (2x+1)dx = 2              ← 精确值，因为 2x+1 的积分是多项式
 *
 * 【为什么函数指针有用】
 *   换个被积函数不用改 integral 的一行代码。
 *   这就是"把变化的部分参数化"——算法固定，具体操作由调用者决定。
 *   标准库的 qsort 也是这个思路：排序算法你写一次，
 *   "怎么比较两个元素"由你传进去的函数决定。
 */

#include <stdio.h>
#include <math.h>

/* 三个被积函数 */
double f_cos(double x)
{
    // TODO
    return 0.0;
}

double f_sin(double x)
{
    // TODO
    return 0.0;
}

double f_linear(double x)
{
    // TODO
    return 0.0;
}

/* 通用定积分函数，f 是函数指针 */
double integral(double a, double b, long n, double (*f)(double))
{
    // TODO: 中点法
    return 0.0;
}

int main(void)
{
    // TODO: 三次调用 integral，分别传 f_cos / f_sin / f_linear
    //       输出格式：cos=%.8f  等

    return 0;
}
