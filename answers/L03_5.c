/* L03_5 参考答案 · 9 位数拆三个三位数 */

#include <stdio.h>

int main(void)
{
    long n;

    scanf("%ld", &n);

    printf("%ld %ld %ld\n", n / 1000000, n / 1000 % 1000, n % 1000);

    return 0;
}
