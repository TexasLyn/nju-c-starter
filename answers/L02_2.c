/* L02_2 参考答案 · 长方体体积 */

#include <stdio.h>

int main(void)
{
    int length, width, height;
    int volume;

    scanf("%d %d %d", &length, &width, &height);

    volume = length * width * height;

    printf("%d\n", volume);

    return 0;
}
