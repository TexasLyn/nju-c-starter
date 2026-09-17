/*
 * L11_2 · 求多个整数集合的交集
 *
 * 【题目】（经典题）
 *   读入 k 个整数集合，求它们的交集（在所有集合里都出现过的数）。
 *
 * 【输入格式】
 *   第一行：一个整数 k（集合个数，2 <= k <= 10）
 *   接下来 k 行：每行先是一个整数 c（该集合的元素个数），然后是 c 个整数
 *
 * 【输出格式】
 *   交集里的所有元素，用空格分隔，【按从小到大】排列，占一行。
 *   如果交集为空，输出 empty
 *
 * 【样例 1】
 *   输入：
 *   3
 *   4 1 2 3 4
 *   3 2 3 5
 *   4 2 3 6 7
 *   输出：
 *   2 3
 *
 * 【样例 2】
 *   输入：
 *   2
 *   3 1 2 3
 *   2 4 5
 *   输出：
 *   empty
 *
 * 【思路：拿第一个集合的每个元素，去其余集合里查】
 *
 *   这是最直观的做法：
 *
 *       for (第一个集合的每个元素 x) {
 *           假设 x 在所有集合里都有 (ok = 1)
 *           for (第 2 个到第 k 个集合) {
 *               在这个集合里找 x
 *               找不到 → ok = 0，break
 *           }
 *           if (ok) 把 x 记进结果
 *       }
 *
 * 【数据怎么存】
 *   因为每个集合的元素个数不同，用【二维数组 + 一维长度数组】：
 *
 *       int set[MAXK][MAXC];        (set[i][j] 是第 i 个集合的第 j 个元素)
 *       int len[MAXK];              (len[i] 是第 i 个集合的元素个数)
 *
 *   读入时：
 *       scanf("%d", &k);
 *       for (int i = 0; i < k; i++) {
 *           scanf("%d", &len[i]);
 *           for (int j = 0; j < len[i]; j++) {
 *               scanf("%d", &set[i][j]);
 *           }
 *       }
 *
 * 🔸 注意 set[i] 的【有效长度是 len[i]】，后面的格子是没用的。
 *    遍历第 i 个集合时，循环上界是 len[i]，不是 MAXC。
 *    这就是第 11 课开头说的"二维数组的行长度可以不一样，
 *    但要自己用另一个数组记住每行多长"。
 *
 * 【排序怎么做】
 *   收集到结果数组 res[0..m-1] 之后，用简单的选择排序：
 *
 *       for (int i = 0; i < m; i++) {
 *           for (int j = i + 1; j < m; j++) {
 *               if (res[i] > res[j]) {
 *                   交换 res[i] 和 res[j];
 *               }
 *           }
 *       }
 *
 *   这是第 5 课的三数排序推广到 m 个数，逻辑一样：
 *   每轮把最小的放到位置 i。
 *
 * 【⚠️ 两个容易错的地方】
 *
 *   1. 遍历集合时上界必须是 len[i]，写成 MAXC 会读到无效数据。
 *
 *   2. 判断"在所有集合里都有"时，用标志变量：
 *           int inAll = 1;
 *           for (int i = 1; i < k; i++) {
 *               int found = 0;
 *               for (int j = 0; j < len[i]; j++)
 *                   if (set[i][j] == x) { found = 1; break; }
 *               if (!found) { inAll = 0; break; }      (有一个没有就够了)
 *           }
 *      注意两层标志，别混。
 */

#include <stdio.h>

#define MAXK 10
#define MAXC 100

int main(void)
{
    int k;
    int set[MAXK][MAXC];
    int len[MAXK];
    int res[MAXC];
    int m = 0;

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; j++) {
            scanf("%d", &set[i][j]);
        }
    }

    // TODO 1: 找出所有集合共有的元素，收集到 res，个数记在 m

    // TODO 2: 把 res 从小到大排序

    // 输出
    if (m == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < m; i++) {
            printf("%d", res[i]);
            if (i < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
