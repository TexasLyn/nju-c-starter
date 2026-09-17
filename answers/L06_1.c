/* L06_1 参考答案 · 找最大数及其出现次数 */

#include <stdio.h>

int main(void)
{
    int x;
    int max = -2147483647 - 1;
    int cnt = 0;

    scanf("%d", &x);

    while (x != -1) {
        if (x > max) {
            max = x;
            cnt = 1;          /* 换了新的最大值，计数重新开始 */
        } else if (x == max) {
            cnt++;
        }
        scanf("%d", &x);      /* 读下一个 */
    }

    printf("%d %d\n", max, cnt);

    return 0;
}
