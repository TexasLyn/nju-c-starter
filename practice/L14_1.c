/*
 * L14_1 · 反序素数写入文件（上机常见题型）
 *
 * 【题目】
 *   定义"反序素数"：本身是素数，把它各位数字反过来也是素数。
 *   例如 13 是素数，反序得 31，31 也是素数 → 13 是反序素数。
 *   再如 11 → 11，是；23 → 32，32 不是素数，所以 23 不是。
 *
 *   实现函数：
 *
 *       int rev_prime(int m, int n, int x[])
 *
 *   求出 [m, n] 区间内所有反序素数，依次存入数组 x，返回个数。
 *
 *   然后在 main 里：
 *       1. 从键盘读入 m 和 n
 *       2. 调用 rev_prime
 *       3. 【把结果写入文件 out.txt】，格式见下
 *       4. 同时把同样的内容打印到屏幕（方便你确认）
 *
 * 【文件格式要求】
 *   第一行：个数
 *   第二行：所有反序素数，用空格分隔（没有则输出空行）
 *
 * 【输入格式】
 *   两个整数 m n，用空格分隔。
 *
 * 【输出格式（屏幕和文件内容相同）】
 *   13
 *   2 3 5 7 11 13 17 31 37 71 73 79 97
 *
 * 【样例】
 *   输入 1 100   →  第一行 13，第二行是上面那串
 *   输入 10 200  →  第一行 21
 *   输入 14 16   →  第一行 0，第二行是空行
 *
 * 【需要两个辅助函数】
 *
 *   (判断素数)
 *   int is_prime(int n)
 *   {
 *       if (n < 2) return 0;
 *       for (int i = 2; i * i <= n; i++)
 *           if (n % i == 0) return 0;
 *       return 1;
 *   }
 *
 *   (求反序数)
 *   int reverse_num(int n)
 *   {
 *       int r = 0;
 *       while (n > 0) {
 *           r = r * 10 + n % 10;
 *           n = n / 10;
 *       }
 *       return r;
 *   }
 *
 *   这两个函数你在第 7、8 课都写过，直接用。
 *
 * 【rev_prime 的逻辑】
 *
 *       int k = 0;
 *       for (int i = m; i <= n; i++) {
 *           if (is_prime(i) && is_prime(reverse_num(i))) {
 *               x[k] = i;
 *               k++;
 *           }
 *       }
 *       return k;
 *
 * 【⚠️ 写文件的部分（本课重点，上机练习必考）】
 *
 *       FILE *fp = fopen("out.txt", "w");
 *
 *       if (fp == NULL) {                   (⚠️ 必须检查)
 *           return 1;
 *       }
 *
 *       fprintf(fp, "%d\n", k);
 *
 *       for (int i = 0; i < k; i++) {
 *           if (i > 0) fprintf(fp, " ");
 *           fprintf(fp, "%d", x[i]);
 *       }
 *       fprintf(fp, "\n");
 *
 *       fclose(fp);                         (⚠️ 必须关闭)
 *
 * 【⚠️ 三个必须做对的点】
 *
 *   1. fopen 之后检查 fp == NULL
 *   2. 最后一个数后面不要多一个空格（用 if (i > 0) 控制）
 *   3. fclose 不能忘
 *
 * 【⚠️ 关于 k == 0 的情况】
 *   循环一次都不执行，只输出 "%d\n" 的 0 和一个换行。
 *   第二行是空行 —— 这和期望输出一致（末尾的空行会被评测脚本忽略）。
 *   如果你担心，可以特判 k == 0 时不输出第二行，但那样不符合题目格式。
 *   按上面的代码写就对。
 *
 * 【⚠️ 文件写到哪里去了】
 *   在 CLion 里运行，文件会生成在【运行配置的工作目录】，
 *   通常是 cmake-build-debug/ 目录（不是源代码目录）。
 *   想找到它：在 CLion 里右键项目 → Open in → Finder，
 *   然后找 cmake-build-debug/out.txt。
 *   或者直接改成绝对路径：
 *       fopen("./out.txt", "w");
 */

#include <stdio.h>

/* 判断素数 */
int is_prime(int n)
{
    // TODO
    return 0;
}

/* 求反序数 */
int reverse_num(int n)
{
    // TODO
    return 0;
}

/* 找出 [m,n] 里的反序素数存入 x，返回个数 */
int rev_prime(int m, int n, int x[])
{
    // TODO
    return 0;
}

int main(void)
{
    int m, n;
    int x[1000];
    int k;

    scanf("%d %d", &m, &n);

    k = rev_prime(m, n, x);

    // TODO 1: 把结果写入 out.txt
    //         （提示：fopen → 检查 NULL → fprintf → fclose）

    // TODO 2: 把同样的内容打印到屏幕
    //         （第一行 k，第二行用空格分隔的数）

    return 0;
}
