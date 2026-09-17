/* L05_5 参考答案 · 死循环 + 边界差 1 */

#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;

    while (i <= 100) {      /* 原来写的是 i < 100，漏了 100 */
        sum = sum + i;
        i++;                /* 原来漏了这一句，导致死循环 */
    }

    printf("%d\n", sum);

    return 0;
}
