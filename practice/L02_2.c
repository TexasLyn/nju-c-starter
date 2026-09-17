/*
 * L02_2 · 输入长宽高，求长方体体积
 *
 * 【题目】（经典题）
 *   从键盘读入长方体的长、宽、高（都是整数），计算并输出它的体积。
 *
 * 【输入格式】
 *   三个整数，用空格分隔。例如：
 *   3 4 5
 *
 * 【输出格式】
 *   一个整数，占一行。例如上面输入应输出：
 *   60
 *
 * 【提示】
 *   - 三个 scanf 已经帮你写好了
 *   - 体积 = 长 × 宽 × 高
 *   - 你要补的是：声明一个变量存体积、算出来、打印
 *
 * 【注意】
 *   三个 int 相乘，结果还是 int。如果数字很大（比如 2000*2000*2000）
 *   会超出 int 的范围而溢出。这道题的数字不大，不用管。
 */

#include <stdio.h>

int main(void)
{
    int length, width, height;

    scanf("%d %d %d", &length, &width, &height);

    // TODO 1: 声明一个变量 volume
    int volume;
    // TODO 2: 算出体积
    volume = width * height * length;
    // TODO 3: 打印体积，末尾换行
    printf("%d\n",volume);
    return 0;
}
