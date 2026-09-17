/* L14_2 参考答案 · 读文件统计 */

#include <stdio.h>

int main(void)
{
    int x;
    int cnt = 0;
    int sum = 0;
    int max = 0;
    int min = 0;

    FILE *fin = fopen("in.txt", "r");

    if (fin == NULL) {
        printf("找不到 in.txt\n");
        return 1;
    }

    while (fscanf(fin, "%d", &x) == 1) {
        if (cnt == 0) {
            max = x;                    /* 第一个数同时初始化 max 和 min */
            min = x;
        } else {
            if (x > max) {
                max = x;
            }
            if (x < min) {
                min = x;
            }
        }

        sum = sum + x;
        cnt++;
    }

    fclose(fin);

    FILE *fout = fopen("out.txt", "w");

    if (fout == NULL) {
        printf("无法创建 out.txt\n");
        return 1;
    }

    fprintf(fout, "count=%d\n", cnt);
    fprintf(fout, "max=%d\n", max);
    fprintf(fout, "min=%d\n", min);
    fprintf(fout, "sum=%d\n", sum);

    fclose(fout);

    printf("count=%d\n", cnt);
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    printf("sum=%d\n", sum);

    return 0;
}
