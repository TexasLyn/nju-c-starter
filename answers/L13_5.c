/* L13_5 参考答案 · 结构体分号与访问运算符 */

#include <stdio.h>
#include <string.h>

struct Student {
    int id;                     /* 错误 1：这里漏了分号 */
    char name[20];
};                              /* 错误 2：这里漏了分号 */

int main(void)
{
    struct Student s;
    struct Student *p = &s;

    s.id = 1;
    strcpy(s.name, "张三");

    /* 错误 3：p 是指针，要用 -> ；s 是变量，用 . */
    printf("%d %s\n", p->id, s.name);

    return 0;
}
