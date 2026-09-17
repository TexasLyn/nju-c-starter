/*
 * L13_5 · 找错题：结构体分号与 . / -> 混用
 *
 * 【注意】下面这个结构体定义【故意包含 3 处错误】，所以本文件编译不通过
 *         是正常的，那正是你要修的东西。评测脚本会跳过它的编译检查。
 *
 * @NOCOMPILE
 *
 * 【题目】
 *   下面这段程序想存一个学生的信息并打印，它有【三处】错误。
 *   请找出并按正确方式重写。
 *
 * 【有错误的程序（就是本文件下半部分的内容）】
 *   ────────────────────────────────────────
 *   struct Student {
 *       int  id
 *       char name[20];
 *   }
 *
 *   int main(void)
 *   {
 *       struct Student s;
 *       struct Student *p = &s;
 *
 *       s.id = 1;
 *       strcpy(s.name, "张三");
 *
 *       printf("%d %s\n", p.id, p->name);
 *       return 0;
 *   }
 *   ────────────────────────────────────────
 *
 * 【错误分析】
 *
 *   错误 1：`int id` 后面漏了分号。
 *       结构体的字段声明也是语句，每条末尾都要分号。
 *       报错信息可能指向【下一行】，比较迷惑：
 *           error: expected ';' at end of declaration list
 *
 *   错误 2：结构体定义的 `}` 后面漏了分号。
 *       这是本课反复强调的头号坑：
 *           struct Student {
 *               ...
 *           };                    ← 这个分号必须有
 *
 *       报错信息通常是一大堆莫名其妙的，比如
 *           error: expected identifier or '('
 *       因为编译器以为你在 `}` 后面还要继续声明变量。
 *
 *   错误 3：`p.id` 用错了运算符。
 *       p 是一个【指针】，访问字段要用 `->`，不是 `.`。
 *       好消息：这种错编译器会明确提示，还会告诉你该怎么改：
 *           error: member reference type 'struct Student *' is a pointer;
 *                  did you mean to use '->'?
 *
 * 【你要做的】
 *   把下面 3 处 TODO 全部改成正确的，然后运行，应该输出：
 *   1 张三
 *
 * 【想亲眼看看这些报错长什么样】
 *   现在就可以试着编译一下这个文件（CLion 里点运行，或者
 *   clang -std=c11 practice/L13_5.c -o /tmp/x）。
 *   【强烈建议试一次】—— 亲眼见过那种"报错指向下一行"的迷惑现象，
 *   以后在练习里遇到就知道该往上看一行找漏掉的分号了。
 *
 * 【⚠️ 顺带提醒】
 *   如果结构体里要放指向自己的指针（链表节点那种），
 *   自引用必须写 `struct Student *next`，不能写别名。
 *   本题没用到，但这条规则必须记住。
 */

#include <stdio.h>
#include <string.h>

struct Student {
    int id          /* TODO 1: 这一行末尾缺个字符 */
    char name[20];
}                   /* TODO 2: 这一行末尾也缺个字符 */

int main(void)
{
    struct Student s;
    struct Student *p = &s;

    s.id = 1;
    strcpy(s.name, "张三");

    printf("%d %s\n", p.id, p->name);   /* TODO 3: 这里面有一处的运算符用错了 */

    return 0;
}
