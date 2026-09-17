/* L07_5 参考答案 · 递归进制转换 */

#include <stdio.h>

void convert(int n, int base)
{
    if (n >= base) {
        convert(n / base, base);    /* 先递归处理高位 */
    }

    int d = n % base;               /* 再输出本位 */

    if (d < 10) {
        printf("%d", d);
    } else {
        printf("%c", 'A' + d - 10);
    }
}

int main(void)
{
    int n, base;

    scanf("%d %d", &n, &base);

    convert(n, base);
    printf("\n");

    return 0;
}
