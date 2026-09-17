/* L07_4 参考答案 · 递归判断素数 */

#include <stdio.h>

int is_prime_rec(int n, int i)
{
    if (n < 2) {
        return 0;                   /* 出口 1：太小，不是素数 */
    }
    if (i * i > n) {
        return 1;                   /* 出口 2：试完了，没找到因子 → 是素数 */
    }
    if (n % i == 0) {
        return 0;                   /* 出口 3：找到因子 → 不是素数 */
    }
    return is_prime_rec(n, i + 1);  /* 递归：试下一个因子 */
}

int main(void)
{
    int m, n;

    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        if (is_prime_rec(i, 2)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
