/* L14_4 参考答案 · 统计文件的字符/单词/行数 */

#include <stdio.h>

int main(void)
{
    char fname[100];
    int c;
    int chars = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    scanf("%s", fname);

    FILE *fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("找不到文件 %s\n", fname);
        return 1;
    }

    /* c 必须是 int：EOF 是 -1，char 装不下 */
    while ((c = fgetc(fp)) != EOF) {
        chars++;

        if (c == '\n') {
            lines++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            inWord = 0;
        } else {
            if (!inWord) {              /* 从空白进入非空白 → 新单词 */
                words++;
                inWord = 1;
            }
        }
    }

    fclose(fp);

    FILE *fout = fopen("out.txt", "w");

    if (fout == NULL) {
        printf("无法创建 out.txt\n");
        return 1;
    }

    fprintf(fout, "chars=%d\n", chars);
    fprintf(fout, "words=%d\n", words);
    fprintf(fout, "lines=%d\n", lines);
    fclose(fout);

    printf("chars=%d\n", chars);
    printf("words=%d\n", words);
    printf("lines=%d\n", lines);

    return 0;
}
