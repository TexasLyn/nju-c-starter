/* L05_1 参考答案 · 四元不定方程（for 和 while 各一遍） */

#include <stdio.h>

int main(void)
{
    int count1 = 0;
    int count2 = 0;

    /* ---- for 版本 ---- */
    for (int x1 = 1; x1 <= 27; x1++) {
        for (int x2 = 1; x2 <= 27; x2++) {
            for (int x3 = 1; x3 <= 27; x3++) {
                for (int x4 = 1; x4 <= 27; x4++) {
                    if (x1 + x2 + x3 + x4 == 30) {
                        count1++;
                    }
                }
            }
        }
    }

    /* ---- while 版本 ---- */
    /* 注意内层变量必须在外层循环体内部初始化，否则第二轮不会归位 */
    int a1 = 1;
    while (a1 <= 27) {
        int a2 = 1;
        while (a2 <= 27) {
            int a3 = 1;
            while (a3 <= 27) {
                int a4 = 1;
                while (a4 <= 27) {
                    if (a1 + a2 + a3 + a4 == 30) {
                        count2++;
                    }
                    a4++;
                }
                a3++;
            }
            a2++;
        }
        a1++;
    }

    printf("%d %d\n", count1, count2);

    return 0;
}
