/* L15_6 参考答案 · 字符串数组按长度重排 */

#include <stdio.h>
#include <string.h>

#define MAXN 100

int main(void)
{
    char buf[MAXN][20];
    char out[MAXN][20];
    int n;
    int minIdx = 0, maxIdx = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", buf[i]);
    }

    /* 找最短和最长的下标 */
    for (int i = 1; i < n; i++) {
        if (strlen(buf[i]) < strlen(buf[minIdx])) {
            minIdx = i;
        }
        if (strlen(buf[i]) > strlen(buf[maxIdx])) {
            maxIdx = i;
        }
    }

    /* 构造结果：最短 + 其余（保持原顺序）+ 最长 */
    int k = 0;

    strcpy(out[k], buf[minIdx]);
    k++;

    for (int i = 0; i < n; i++) {
        if (i == minIdx || i == maxIdx) {
            continue;
        }
        strcpy(out[k], buf[i]);
        k++;
    }

    if (minIdx != maxIdx) {         /* 全部等长时不要重复放 */
        strcpy(out[k], buf[maxIdx]);
        k++;
    }

    FILE *fp = fopen("out.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    for (int i = 0; i < k; i++) {
        fprintf(fp, "%s\n", out[i]);
        printf("%s\n", out[i]);
    }

    fclose(fp);

    return 0;
}
