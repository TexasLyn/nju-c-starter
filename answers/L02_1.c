/* L02_1 参考答案 · 用 sizeof 量各种类型 */

#include <stdio.h>

int main(void)
{
    printf("int %zu\n", sizeof(int));
    printf("long %zu\n", sizeof(long));
    printf("float %zu\n", sizeof(float));
    printf("double %zu\n", sizeof(double));
    printf("char %zu\n", sizeof(char));
    printf("short %zu\n", sizeof(short));

    return 0;
}
