/* L09_2 参考答案 · static 统计调用次数 */

#include <stdio.h>

int how_many(void)
{
    static int cnt = 0;         /* 只初始化一次 */
    cnt++;
    return cnt;
}

int main(void)
{
    for (int i = 0; i < 5; i++) {
        printf("%d\n", how_many());
    }

    return 0;
}
