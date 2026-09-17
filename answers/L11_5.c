/* L11_5 参考答案 · 二维数组传参与循环上界 */

#include <stdio.h>

int sum_matrix(int a[][4], int rows)     /* 原来写的 int a[][] ，缺列数 */
{
    int s = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            s = s + a[i][j];
        }
    }

    return s;
}

int main(void)
{
    int m[3][4];
    int total = 0;

    for (int i = 0; i < 3; i++) {           /* 原来写反了：i < 4 */
        for (int j = 0; j < 4; j++) {       /* 原来写反了：j < 3 */
            scanf("%d", &m[i][j]);
        }
    }

    total = sum_matrix(m, 3);
    printf("%d\n", total);

    return 0;
}
