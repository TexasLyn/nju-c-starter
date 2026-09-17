/*
 * L14_5 · 找错题：fopen / fclose 用错
 *
 * 【题目】
 *   下面这段程序想把 1 到 5 的平方写进文件 out.txt。
 *   它有【三处】问题，请找出来并改正。
 *
 * 【有问题的程序】
 *   ────────────────────────────────────────
 *   #include <stdio.h>
 *
 *   int main(void)
 *   {
 *       FILE *fp = fopen("out.txt", "r");
 *
 *       for (int i = 1; i <= 5; i++) {
 *           fprintf(fp, "%d %d\n", i, i * i);
 *       }
 *
 *       return 0;
 *   }
 *   ────────────────────────────────────────
 *
 * 【问题分析】
 *
 *   问题 1（最严重）：模式用了 `"r"`，应该是 `"w"`。
 *
 *       `"r"` 是【只读】模式。用只读模式去 fprintf 写数据，
 *       行为是未定义的 —— 可能什么也没写，可能崩溃，可能乱写。
 *
 *       而且如果 out.txt 不存在，`fopen("out.txt", "r")` 会返回 NULL，
 *       那 fprintf(NULL, ...) 直接崩溃（Segmentation fault）。
 *
 *       正确：`fopen("out.txt", "w")`
 *
 *   问题 2：没有检查 fopen 的返回值。
 *
 *       文件打不开时 fp 是 NULL，后面所有操作都会崩溃。
 *       必须加：
 *           if (fp == NULL) {
 *               printf("打开文件失败\n");
 *               return 1;
 *           }
 *
 *   问题 3：没有 fclose。
 *
 *       不关闭文件，缓冲区里的数据可能还没真正写入磁盘。
 *       程序结束时操作系统通常会帮你刷新，但这是不可靠的。
 *       而且如果你后续要读这个文件，不 fclose 就读不到最新内容。
 *
 *       正确：在 return 之前加 `fclose(fp);`
 *
 * 【你要做的】
 *   写出正确的程序，让 out.txt 的内容是：
 *   1 1
 *   2 4
 *   3 9
 *   4 16
 *   5 25
 *
 *   同时屏幕上也打印同样的内容。
 *
 * 【⚠️ 顺便想一个问题】
 *   如果在 CLion 里运行，out.txt 会生成在哪个目录？
 *   【答】运行配置的工作目录，通常是 cmake-build-debug/。
 *   想确认的话，在程序里加一句 system("pwd"); （需要 stdlib.h），
 *   或者直接用绝对路径。
 */

#include <stdio.h>

int main(void)
{
    // TODO 1: 用正确的模式打开文件，并检查是否成功

    for (int i = 1; i <= 5; i++) {
        // TODO 2: 写入文件
        // TODO 3: 同时打印到屏幕
    }

    // TODO 4: 关闭文件

    return 0;
}
