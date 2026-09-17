/* L03_1 参考答案 · 分离符号、整数部分、小数部分 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    scanf("%lf", &x);

    if (x < 0) {
        printf("Sign:-\n");
    } else {
        printf("Sign:+\n");
    }

    double a = fabs(x);      /* 转成正数，方便处理 */
    int ip = (int)a;         /* 强制转 int，小数部分被砍掉 */
    printf("Integral part:%d\n", ip);

    double dp = a - ip;
    printf("Decimal fraction part:%.6f\n", dp);

    return 0;
}
