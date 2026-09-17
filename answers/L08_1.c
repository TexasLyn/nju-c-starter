/* L08_1 参考答案 · 宏展开 */

#include <stdio.h>
#include <math.h>

#define M 3
#define N M + 1
#define SQR(x) ((x)*(x))

int main(void)
{
    printf("%d\n", M * N);        /* 3 * M + 1 → 3 * 3 + 1 → 10 */
    printf("%d\n", SQR(M + 1));   /* ((3+1)*(3+1)) → 16 */
    printf("%d\n", SQR(N));       /* ((M+1)*(M+1)) → ((3+1)*(3+1)) → 16 */

    return 0;
}
