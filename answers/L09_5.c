/* L09_5 参考答案 · #ifdef 与 #if */

#include <stdio.h>

#define Z 0
#define Y 1

int main(void)
{
#ifdef Z
    printf("A\n");              /* 输出：Z 定义过 */
#endif

#ifndef Z
    printf("B\n");              /* 不输出 */
#endif

#if Z
    printf("C\n");              /* 不输出：值是 0，假 */
#endif

#ifdef Y
    printf("D\n");              /* 输出：Y 定义过 */
#endif

#if Y
    printf("E\n");              /* 输出：值是 1，真 */
#endif

    return 0;
}
