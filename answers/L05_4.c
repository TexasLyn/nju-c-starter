/* L05_4 参考答案 · 六位回文完全平方数（遍历平方根） */

#include <stdio.h>

int main(void)
{
    /* 六位数 n = r*r，所以 r 在 317 到 999 之间，只有 683 个候选 */
    for (long r = 317; r <= 999; r++) {
        long n = r * r;

        if (n / 100000 == n % 10
            && n / 10000 % 10 == n / 10 % 10
            && n / 1000 % 10 == n / 100 % 10) {
            printf("%ld %ld\n", n, r);
        }
    }

    return 0;
}
