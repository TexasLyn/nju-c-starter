/*
 * L02_1 · 用 sizeof 量出各种类型占几个字节
 *
 * 【题目】（经典题）
 *   输出下面几种类型各占多少个字节：
 *       int, long, float, double, char, short
 *
 *   输出格式：每行一个，"类型名 空格 字节数"
 *   不要输出现成的数字，要用 sizeof 运算符去量。
 *
 * 【期望输出】
 *   int 4
 *   long 8
 *   float 4
 *   double 8
 *   char 1
 *   short 2
 *
 * 【提示】
 *   - 打印 sizeof 的结果用 %zu，不是 %d
 *   - sizeof 后面要加括号：sizeof(int)
 *   - 一共 6 句 printf
 *
 * 【想一想】
 *   为什么 int 是 4 个字节？4 个字节 = 32 位，能表示 2^32 个数，
 *   一半正一半负，所以范围是 -2^31 到 2^31-1，也就是约 ±21 亿。
 */

#include <stdio.h>

int main(void)
{
    printf("int %zu\n",sizeof(int));
    printf("long %zu\n",sizeof(long));
    printf("float %zu\n",sizeof(float));
    printf("double %zu\n",sizeof(double));
    printf("char %zu\n",sizeof(char));
    printf("short %zu\n",sizeof(short));
    // TODO: 写 6 句 printf，分别量 int / long / float / double / char / short

    return 0;
}
