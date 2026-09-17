/*
 * L13_1 · 联系人数组：delete / sort / display
 *
 * 【题目】（经典题）
 *   用结构体数组管理联系人，实现三个函数：
 *
 *       void display(PS *ps, int n);              (显示所有联系人)
 *       int  delete_by_id(PS *ps, int n, int id); (删除指定编号，返回新个数)
 *       void sort_by_id(PS *ps, int n);           (按编号升序排序)
 *
 *   联系人类型定义（已经给你了）：
 *
 *       typedef struct {
 *           int  id;
 *           char name[20];
 *           char sex[8];
 *       } PS;
 *
 * 【输入格式】
 *   第一行：一个整数 n（联系人个数）
 *   接下来 n 行：每行 "id name sex"
 *   接下来一行：要删除的 id
 *
 * 【输出格式】
 *   第一行：删除后的个数
 *   接下来：按 id 升序排列的联系人，每行 "id name sex"
 *
 * 【样例】
 *   输入：
 *   3
 *   3 王五 男
 *   1 张三 男
 *   2 李四 女
 *   2
 *   输出：
 *   2
 *   1 张三 男
 *   3 王五 男
 *
 * 【样例分析】
 *   原数组：[3 王五]、[1 张三]、[2 李四]
 *   删除 id=2 → [3 王五]、[1 张三]（剩下 2 个）
 *   按 id 升序 → [1 张三]、[3 王五]
 *
 * 【删除的实现：用"双下标"平移】
 *   这就是第 10 课 L10_2 那个"双下标"技巧的结构体版本：
 *
 *       int delete_by_id(PS *ps, int n, int id)
 *       {
 *           int k = 0;
 *
 *           for (int i = 0; i < n; i++) {
 *               if (ps[i].id != id) {        (不是要删的，就保留)
 *                   ps[k] = ps[i];           (⚠️ 结构体可以整体赋值！)
 *                   k++;
 *               }
 *           }
 *
 *           return k;
 *       }
 *
 *   🔸 注意 `ps[k] = ps[i];` 这一句 —— 结构体支持整体赋值（本课重点），
 *      不用逐个字段复制。如果 PS 里有个 char 数组字段，也一样能整体拷。
 *
 * 【排序的实现：交换结构体】
 *   也可以用整体赋值来交换，很方便：
 *
 *       void sort_by_id(PS *ps, int n)
 *       {
 *           for (int i = 0; i < n; i++) {
 *               for (int j = i + 1; j < n; j++) {
 *                   if (ps[i].id > ps[j].id) {
 *                       PS t = ps[i];            (整体拷贝)
 *                       ps[i] = ps[j];
 *                       ps[j] = t;
 *                   }
 *               }
 *           }
 *       }
 *
 *   🔸 对比第 11 课 L11_3 那个二维数组按行排序：
 *      那里要【用循环逐个元素交换】4 个 int；
 *      这里只用三句整体赋值就搞定。
 *      【这就是结构体带来的便利。】
 *
 * 【⚠️ 关于 char name[20] 的赋值】
 *   结构体整体赋值时，内部的 char 数组会被一起拷贝，没问题。
 *   但单独给字段赋值要注意：
 *       ps[0].name = "张三";          (✗ 数组不能整体赋值)
 *       strcpy(ps[0].name, "张三");   (✓)
 *   读入的时候用 scanf 就没事（scanf 是往地址里写）：
 *       scanf("%d %s %s", &ps[i].id, ps[i].name, ps[i].sex);
 *   🔸 注意 name 和 sex 前面【没有 &】，因为它们是数组名（就是地址）。
 *      而 id 前面【有 &】，因为它是 int。
 *      这个差别第 3 课和第 12 课都讲过。
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    int  id;
    char name[20];
    char sex[8];
} PS;

/* 显示所有联系人 */
void display(PS *ps, int n)
{
    // TODO
}

/* 删除指定 id 的联系人，返回删除后的个数 */
int delete_by_id(PS *ps, int n, int id)
{
    // TODO
    return n;
}

/* 按 id 升序排序（用整体赋值交换） */
void sort_by_id(PS *ps, int n)
{
    // TODO
}

int main(void)
{
    PS ps[100];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        /* 注意：id 前有 &，name 和 sex 前没有（它们是数组） */
        scanf("%d %s %s", &ps[i].id, ps[i].name, ps[i].sex);
    }

    int delId;
    scanf("%d", &delId);

    n = delete_by_id(ps, n, delId);
    sort_by_id(ps, n);

    printf("%d\n", n);
    display(ps, n);

    return 0;
}
