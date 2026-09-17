/* L04_4 参考答案 · 星期首字母 */

#include <stdio.h>

int main(void)
{
    char c1, c2;

    scanf(" %c", &c1);

    switch (c1) {
    case 'M':
    case 'm':
        printf("Monday\n");
        break;
    case 'W':
    case 'w':
        printf("Wednesday\n");
        break;
    case 'F':
    case 'f':
        printf("Friday\n");
        break;
    case 'T':
    case 't':
        scanf(" %c", &c2);
        if (c2 == 'u' || c2 == 'U') {
            printf("Tuesday\n");
        } else {
            printf("Thursday\n");
        }
        break;
    case 'S':
    case 's':
        scanf(" %c", &c2);
        if (c2 == 'a' || c2 == 'A') {
            printf("Saturday\n");
        } else {
            printf("Sunday\n");
        }
        break;
    default:
        break;
    }

    return 0;
}
