/*
 * L15_6 · 编程题：字符串数组按长度重排
 *
 * 【上机练习编程题的标准形态】
 *
 * 【题目】
 *   读入 n 个字符串（不含空格）。要求：
 *       把【最短】的那个移到数组最前面
 *       把【最长】的那个移到数组最后面
 *       其余元素的【相对顺序保持不变】
 *   输出重排后的数组，并写入文件 out.txt。
 *
 * 【输入格式】
 *   第一行：整数 n
 *   接下来 n 行：每行一个字符串（长度不超过 19，不含空格）
 *
 * 【输出格式】
 *   重排后的字符串，每行一个（屏幕和 out.txt 内容一致）。
 *
 * 【样例 1】
 *   输入：
 *   5
 *   apple
 *   hi
 *   banana
 *   cat
 *   dog
 *   输出：
 *   hi
 *   apple
 *   cat
 *   dog
 *   banana
 *
 *   分析：
 *       原顺序：apple(5) hi(2) banana(6) cat(3) dog(3)
 *       hi 最短 → 提到最前
 *       banana 最长 → 挪到最后
 *       剩下的 apple、cat、dog 按原来的先后顺序排列
 *       结果：hi, apple, cat, dog, banana  ✓
 *
 * 【样例 2】最短和最长已经在两头
 *   输入：
 *   3
 *   a
 *   bb
 *   ccc
 *   输出：
 *   a
 *   bb
 *   ccc
 *
 * 【样例 3】所有字符串一样长
 *   输入：
 *   3
 *   aa
 *   bb
 *   cc
 *   输出：
 *   aa
 *   bb
 *   cc
 *   （最短和最长是同一个元素，数组保持原样）
 *
 * 【⚠️ 为什么不能"直接交换位置"】
 *   如果只是把最短元素和 a[0] 交换、最长元素和 a[n-1] 交换，
 *   中间元素的相对顺序会被打乱。
 *
 *   举例：a = [cat, hi, dog]（hi 最短）
 *       交换 a[0] 和 a[1] 得到 [hi, cat, dog] —— 这个碰巧对了。
 *   但如果是 a = [cat, dog, hi]（hi 最短）
 *       交换 a[0] 和 a[2] 得到 [hi, dog, cat] —— cat 和 dog 的顺序反了！
 *
 * 【正确做法：重新构造一个数组】
 *   按"最短 + 其余（保持原顺序）+ 最长"的顺序往新数组里放。
 *   因为我们是【按原顺序遍历】的，所以"相对顺序不变"自动满足。
 *
 *   第一步：找最短和最长的下标 minIdx、maxIdx。
 *
 *   第二步：构造新数组 out：
 *       out[0] = 最短的那个
 *       遍历原数组，把【不是最短也不是最长】的元素依次放进 out
 *       最后 out[n-1] = 最长的那个（但要避免重复放）
 *
 *   第三步：输出 out（也可以拷回 buf）。
 *
 * 【代码框架】
 *
 *       int minIdx = 0, maxIdx = 0;
 *
 *       for (int i = 1; i < n; i++) {
 *           if (strlen(buf[i]) < strlen(buf[minIdx])) minIdx = i;
 *           if (strlen(buf[i]) > strlen(buf[maxIdx])) maxIdx = i;
 *       }
 *
 *       int k = 0;
 *       strcpy(out[k], buf[minIdx]);
 *       k++;
 *
 *       for (int i = 0; i < n; i++) {
 *           if (i == minIdx || i == maxIdx) continue;
 *           strcpy(out[k], buf[i]);
 *           k++;
 *       }
 *
 *       if (minIdx != maxIdx) {
 *           strcpy(out[k], buf[maxIdx]);
 *           k++;
 *       }
 *
 * 【⚠️ 那个 if 是干什么的（本题最容易错的地方）】
 *   当所有字符串一样长时，minIdx 和 maxIdx 会指向同一个元素。
 *   此时：
 *       out[0] 已经把"最短"放进去了（其实也就是那个元素）
 *       遍历时 i 等于 minIdx 和 maxIdx 都被跳过
 *       如果最后还无条件地把"最长"放一遍，那个元素就【出现两次】，
 *       而且 out 的总数会变成 n+1，越界。
 *   加上 `if (minIdx != maxIdx)` 就正确了。
 *
 *   🔸 这个细节说明：写程序时一定要想清楚【特殊情况】，不能只想"正常情况"。
 *
 * 【关于"最短/最长"不唯一时取哪个】
 *   上面的写法用严格的小于/大于比较，所以取的是【第一个遇到的】最短/最长。
 *   评测数据保证不会有歧义。
 *
 * 【字符串数组怎么定义】
 *       char buf[100][20];      (最多 100 个字符串，每个最长 19 字符 + \0)
 *
 *   ⚠️ 每行 20 字节，只能放 19 个字符的字符串。题目说了长度不超过 19，
 *      正好够。
 *
 * 【固定要求】
 *   结果写入 out.txt，内容和屏幕输出一致。
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100

int main(void)
{
    char buf[MAXN][20];
    char out[MAXN][20];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", buf[i]);
    }

    // TODO 1: 找最短和最长的下标 minIdx、maxIdx

    // TODO 2: 按"最短 + 其余 + 最长"的顺序构造 out 数组

    // TODO 3: 写入 out.txt 并打印到屏幕（每行一个）

    return 0;
}
