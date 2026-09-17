/* L06_3 参考答案 · 按规律生成前 20 项 */

#include <stdio.h>

int main(void)
{
    long a = 1;

    printf("%ld\n", a);           /* 第 1 项 */

    for (int n = 2; n <= 20; n++) {
        if (n % 2 == 0) {
            a = a * 2;
        } else {
            a = a + n;
        }
        printf("%ld\n", a);
    }

    return 0;
}
