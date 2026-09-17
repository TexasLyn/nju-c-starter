/* L02_4 参考答案 · 分钟换算成年和天 */

#include <stdio.h>

int main(void)
{
    int total;
    int years, rest, days;

    scanf("%d", &total);

    years = total / 525600;
    rest = total % 525600;
    days = rest / 1440;

    printf("%d %d\n", years, days);

    return 0;
}
