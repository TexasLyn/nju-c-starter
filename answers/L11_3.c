/* L11_3 参考答案 · 按行和排序 */

#include <stdio.h>

void line_sort(int a[][4], int b[], int n);

int main(void)
{
    int a[4][4];
    int rowSum[4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    line_sort(a, rowSum, 4);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", a[i][j]);
            if (j < 3) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++) {
        printf("%d", rowSum[i]);
        if (i < 3) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

void line_sort(int a[][4], int b[], int n)
{
    /* 第一步：算每行的和 b[i] 也要同步一起排序 */
    for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int j = 0; j < 4; j++) {
            b[i] = b[i] + a[i][j];
        }
    }

    /* 第二步：选择排序，交换时整行都要换 */
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (b[i] > b[k]) {
                /* 交换行和 */
                int t = b[i];
                b[i] = b[k];
                b[k] = t;

                /* 交换矩阵的第 i 行和第 k 行：4 个元素都要换 */
                for (int j = 0; j < 4; j++) {
                    int tmp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = tmp;
                }
            }
        }
    }
}
