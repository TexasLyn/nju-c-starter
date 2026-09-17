/* L04_5 参考答案 · 连续比较的坑 */

#include <stdio.h>

int main(void)
{
    int x;

    scanf("%d", &x);

    if (0 < x && x < 100) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
