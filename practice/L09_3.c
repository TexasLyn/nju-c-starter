/*
 * L09_3 · 返回 static 局部变量的地址
 *
 * 【题目】（经典题）
 *   写一个函数 int *count(char *ch)，统计它被调用的次数。
 *   要求：用 static 局部变量存计数，并【返回这个变量的地址】。
 *
 *   main 里调用它 3 次，每次都打印通过返回的指针读到的值。
 *
 * 【输出格式】
 *   三行：
 *   1
 *   2
 *   3
 *
 * 【函数写法】
 *
 *       int *count(char *ch)
 *       {
 *           static int n = 0;        (← 必须是 static！)
 *           n++;
 *           return &n;
 *       }
 *
 * 【⚠️ 为什么必须用 static（这道题的核心考点）】
 *
 *   如果写成普通局部变量：
 *
 *       int *count(char *ch)
 *       {
 *           int n = 0;              (✗ 普通局部变量)
 *           n++;
 *           return &n;              (返回一个即将消失的变量的地址)
 *       }
 *
 *   函数返回后，n 所在的内存被回收，随时可能被别的函数覆盖。
 *   你拿到的是一个【悬空指针】（dangling pointer）——指向已经不属于你的内存。
 *
 *   这种错误的症状很恶劣：
 *       - 有时候读到的值是对的（内存还没被覆盖）
 *       - 有时候是垃圾值（内存已经被用了）
 *       - 有时候程序直接崩溃
 *   【时对时错，最难查。】
 *
 *   用 static 就没事了：static 变量活到程序结束，地址一直有效。
 *
 * 🔸 记住这条规则：
 *   【要返回指针，指向的东西必须活得比函数长。】
 *   可以是 static 变量、全局变量，或者 malloc 出来的内存（第 13 课）。
 *
 * 【main 的写法】
 *
 *       int *p;
 *       p = count("a");
 *       printf("%d\n", *p);          (用 * 读出指针指向的值)
 *
 * 【参数 char *ch 是什么】
 *   这是一个字符串指针（第 12 课细讲）。这道题里函数其实没用它，
 *   只是题目要求有这么一个参数（原题是为了别的用途设计的）。
 *   你调用时随便传个字符串字面量就行，比如 count("a")。
 *
 * 【⚠️ 编译器的警告】
 *   如果你写成普通局部变量，clang 会警告：
 *       warning: address of stack memory associated with local variable 'n' returned
 *   【看到 "address of stack memory ... returned" 一定要改。】
 *   这个警告非常准确，不要忽略。
 */

#include <stdio.h>

/* TODO: 实现 count 函数，返回 static 变量的地址 */
int *count(char *ch)
{
    return 0;
}

int main(void)
{
    // TODO: 调用 3 次，每次用 *p 读出值并打印

    return 0;
}
