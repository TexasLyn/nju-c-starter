/*
 * L12_5 · 找错题：字符串比较和 \0
 *
 * 【题目】
 *   下面这段程序想读入两个单词，判断它们是否相同。
 *   它有【两处】错误：一处能编译但结果永远错，一处会导致编译不过。
 *
 *   请找出错误并写出正确的程序。
 *
 * 【有错误的程序】
 *   ────────────────────────────────────────
 *   #include <stdio.h>
 *
 *   int main(void)
 *   {
 *       char a[10], b[10];
 *
 *       scanf("%s", a);
 *       scanf("%s", b);
 *
 *       if (a == b) {
 *           printf("same\n");
 *       } else {
 *           printf("different\n");
 *       }
 *
 *       return 0;
 *   }
 *   ────────────────────────────────────────
 *
 * 【错误分析】
 *
 *   错误 1（逻辑错误，最严重）：`if (a == b)`
 *
 *       a 和 b 是两个不同的数组，住在内存的不同位置。
 *       `a` 和 `b` 在表达式里会【退化成地址】，
 *       所以 `a == b` 比较的是"两个数组的地址是否相同"。
 *
 *       两个不同的数组地址永远不同，所以这个条件永远不成立，
 *       不管输入什么内容，程序永远输出 "different"。
 *
 *       ⚠️ 【编译器不会报错，也不一定给警告】
 *       程序能跑、有输出、看起来正常，就是答案永远错。
 *       这是 C 里最典型的"静默错误"。
 *
 *       正确写法：用 strcmp
 *           if (strcmp(a, b) == 0) { ... }
 *
 *   错误 2（编译错误）：缺少 `#include <string.h>`
 *
 *       用了 strcmp 就必须包含 string.h。
 *       macOS 的编译器会直接报错：
 *           error: call to undeclared library function 'strcmp'
 *
 * 【你要做的】
 *   写出正确的程序，读入两个单词，相同输出 same，不同输出 different。
 *
 * 【测试数据】
 *   输入 hello hello   →  same
 *   输入 hello world   →  different
 *   输入 abc ABC       →  different（strcmp 区分大小写）
 *
 * 【⚠️ 顺带一提：strcmp 区分大小写】
 *   如果要忽略大小写比较，得自己写循环逐字符转小写，
 *   或者用 strcasecmp（这是 POSIX 扩展，不是标准 C，
 *   在 macOS 上需要 #include <strings.h>，练习里别用）。
 *
 * 【⚠️ 还有一个隐患：数组大小】
 *   这里 a 和 b 都是 char[10]，如果输入的单词超过 9 个字符，
 *   scanf("%s") 会写越界（第 10 课讲的数组越界）。
 *   为安全起见，声明大一点，比如 char a[100]。
 *   也可以用 scanf("%9s", a) 限制最多读 9 个字符。
 *   本题数据都是短单词，用 100 就够了。
 */

#include <stdio.h>
/* TODO 1: 还需要哪个头文件？ */

int main(void)
{
    char a[100], b[100];

    scanf("%s", a);
    scanf("%s", b);

    // TODO 2: 正确的比较和输出

    return 0;
}
