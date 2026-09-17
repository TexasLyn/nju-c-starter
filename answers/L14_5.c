/* L14_5 参考答案 · fopen / fclose */

#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("out.txt", "w");       /* 原来是 "r"，写不进去 */

    if (fp == NULL) {
        printf("打开文件失败\n");
        return 1;
    }

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "%d %d\n", i, i * i);
        printf("%d %d\n", i, i * i);
    }

    fclose(fp);                             /* 原来漏了这一句 */

    return 0;
}
