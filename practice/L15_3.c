/*
 *
 * @NOCOMPILE  （改错题：本文件故意包含错误，编译不过才正常）
 * L15_3 · 改错题：结构体数组按条件筛选
 *
 * 【注意】这个文件【故意包含 4 处错误】，编译或结果是错的。
 *         你的任务是把它们改对。评测脚本会跳过它的编译检查。
 *
 * 【上机题规则】
 *   只能改现有语句的部分内容，不能增加或删除语句。
 *
 * 【题目】
 *   给定若干个职工记录（工号、姓名、工资），
 *   按给定条件筛选出符合条件的记录，存入结果数组并返回个数。
 *
 *   条件字符串 cond 的取值：
 *       "gt2000"   → 工资 > 2000
 *       "lt3000"   → 工资 < 3000
 *       其他        → 全部保留
 *
 * 【输入格式】
 *   第一行：整数 n（职工个数）
 *   接下来 n 行：每行 "工号 姓名 工资"
 *   最后一行：条件字符串
 *
 * 【输出格式】
 *   第一行：筛选出的个数
 *   接下来：每条记录一行 "工号 姓名 工资"
 *
 * 【样例】
 *   输入：
 *   3
 *   1 张三 2500
 *   2 李四 1800
 *   3 王五 3200
 *   gt2000
 *   输出：
 *   2
 *   1 张三 2500
 *   3 王五 3200
 *
 * 【函数签名】
 *
 *       int sift(W s[], int n, char cond[], W res[])
 *
 *   s 是原数组，n 是个数，cond 是条件，res 是结果数组，返回筛选出的个数。
 *
 * 【4 处错误】
 *
 *   错误 1（编译错误）：结构体定义末尾漏了分号。
 *       （本课第 13 课的头号坑，上机题也爱考。）
 *
 *   错误 2（编译错误）：函数里用了 strcmp 但没有对应的 #include。
 *
 *   错误 3（逻辑错误）：比较条件时用了 `=` 而不是 `==`。
 *
 *   错误 4（逻辑错误）：把记录存进 res 时下标用错了，
 *       会导致所有结果都覆盖在第 0 个位置。
 *
 * 【改错顺序：先编译，看报错定位前两处；再运行，对照输出找后两处】
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    int  id;
    char name[20];
    int  salary;
} W                              /* TODO 1: 这里漏了一个字符 */

/* 按条件筛选，返回筛选出的个数 */
int sift(W s[], int n, char cond[], W res[])
{
    int m = 0;

    for (int i = 0; i < n; i++) {
        int keep = 0;

        /* TODO 3: 这里的字符串比较有问题（提示：赋值和比较的区别） */
        if (strcmp(cond, "gt2000") = 0) {
            if (s[i].salary > 2000) {
                keep = 1;
            }
        } else if (strcmp(cond, "lt3000") == 0) {
            if (s[i].salary < 3000) {
                keep = 1;
            }
        } else {
            keep = 1;
        }

        if (keep) {
            /* TODO 4: 存进结果数组的位置下标写错了 */
            res[0] = s[i];
            m++;
        }
    }

    return m;
}

int main(void)
{
    W s[100];
    W res[100];
    int n;
    char cond[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &s[i].id, s[i].name, &s[i].salary);
    }

    scanf("%s", cond);

    int m = sift(s, n, cond, res);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d %s %d\n", res[i].id, res[i].name, res[i].salary);
    }

    return 0;
}
