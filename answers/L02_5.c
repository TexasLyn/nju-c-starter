/* L02_5 参考答案 · 四位数反序输出 */

#include <stdio.h>

int main(void)
{
    int n;
    int reversed;

    scanf("%d", &n);

    /* 先取各位：个位 4、十位 3、百位 2、千位 1
       再反过来放：个位当千位，十位当百位……          */
    reversed = (n % 10) * 1000
             + (n / 10 % 10) * 100
             + (n / 100 % 10) * 10
             + (n / 1000);

    printf("%d\n", reversed);

    return 0;
}
