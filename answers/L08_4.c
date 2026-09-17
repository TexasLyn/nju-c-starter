/* L08_4 参考答案 · 反序数相加生成回文数（指针输出参数） */

#include <stdio.h>

long reverse_num(long n)
{
    long r = 0;

    while (n > 0) {
        r = r * 10 + n % 10;
        n = n / 10;
    }

    return r;
}

int is_palindrome(long n)
{
    return n == reverse_num(n);
}

int fun(long n, long *hw)
{
    int count = 0;

    while (!is_palindrome(n)) {
        n = n + reverse_num(n);
        count++;

        if (count > 10000) {
            *hw = 0;
            return -1;
        }
    }

    *hw = n;
    return count;
}

int main(void)
{
    long n;
    long hw = 0;

    scanf("%ld", &n);

    int steps = fun(n, &hw);

    printf("%d %ld\n", steps, hw);

    return 0;
}
