/*
 * L01_3 参考答案 · 找错题
 *
 * 三处错误：
 *   1. int a, b, sum       → 漏了分号
 *   2. b = 20              → 漏了分号
 *   3. printf(...)         → 漏了分号
 *
 * 注意：只有 3 处错误，题目说的是"3 处错误，导致编译不通过"。
 * 实际上上面那段有错的程序里，漏分号的地方是 3 处（声明行、b=20、printf），
 * 改完就能编译通过。
 */

#include <stdio.h>

int main(void)
{
    int a, b, sum;
    a = 10;
    b = 20;
    sum = a + b;
    printf("和是 %d\n", sum);

    return 0;
}
