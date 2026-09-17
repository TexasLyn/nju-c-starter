/*
 * L13_2 · 结构体数组建链表，按学号升序
 *
 * 【题目】（经典题）
 *   给定一组学生记录（学号、姓名、成绩），
 *   用【结构体数组】建一个【按学号升序】的单向链表。
 *   如果出现学号相同的情况，只保留【成绩较高】的那条记录。
 *
 * 【输入格式】
 *   第一行：一个整数 n
 *   接下来 n 行：每行 "学号 姓名 成绩"
 *
 * 【输出格式】
 *   第一行：链表中的节点个数
 *   接下来：按学号升序输出每条记录，格式 "学号 姓名 成绩"
 *
 * 【样例】
 *   输入：
 *   4
 *   3 王五 80
 *   1 张三 90
 *   2 李四 85
 *   3 王五 95
 *   输出：
 *   3
 *   1 张三 90
 *   2 李四 85
 *   3 王五 95
 *
 * 【样例分析】
 *   第 1 条和第 4 条学号都是 3，但第 4 条成绩 95 > 80，
 *   所以保留 95 那条。最终三个节点，按学号 1、2、3 排列。
 *
 * 【思路：先处理重复，再排序，然后建链表】
 *
 *   分三步，每步都简单：
 *
 *   第一步：处理学号重复（保留成绩高的）
 *       对每条记录，看后面有没有相同学号的：
 *       - 有，且自己的成绩更低 → 把自己标记为"删除"
 *       - 有，且自己的成绩更高 → 把对方标记为"删除"
 *
 *       int dead[100] = {0};                (标记哪些记录要丢弃)
 *
 *       for (int i = 0; i < n; i++) {
 *           if (dead[i]) continue;
 *           for (int j = i + 1; j < n; j++) {
 *               if (dead[j]) continue;
 *               if (stu[i].id == stu[j].id) {
 *                   if (stu[i].score >= stu[j].score) {
 *                       dead[j] = 1;         (丢掉成绩低的 j)
 *                   } else {
 *                       dead[i] = 1;         (丢掉成绩低的 i)
 *                       break;               (i 已经废了，不用再看)
 *                   }
 *               }
 *           }
 *       }
 *
 *   第二步：把留下的记录收集到一个新数组，并按学号排序
 *       用选择排序，结构体整体赋值交换（和第 1 题一样）。
 *
 *   第三步：用尾插法建链表
 *
 *       NODE *head = NULL, *tail = NULL;
 *
 *       for (int i = 0; i < m; i++) {
 *           NODE *p = (NODE *)malloc(sizeof(NODE));
 *           p->stu = alive[i];              (结构体整体赋值)
 *           p->next = NULL;
 *
 *           if (head == NULL) {
 *               head = p;
 *               tail = p;
 *           } else {
 *               tail->next = p;
 *               tail = p;
 *           }
 *       }
 *
 * 【⚠️ 关于"按学号升序建链表"的另一种理解】
 *   题目也可以理解为"边插入边排序"（每插一个都插到正确位置）。
 *   那样代码更复杂。用"先排序再尾插"更简单，结果完全一样。
 *   【上机题时选简单可靠的做法。】
 *
 * 【⚠️ 别忘了 #include <stdlib.h>】
 *   malloc 和 free 都在 stdlib.h 里。忘了会报
 *   "call to undeclared library function 'malloc'"。
 *
 * 【⚠️ 链表节点必须马上写 p->next = NULL】
 *   这是上一节强调过的坑。最后一个节点的 next 是 NULL，
 *   遍历才能正确终止。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int  id;
    char name[20];
    int  score;
} STU;

typedef struct node {
    STU stu;                    /* 数据字段：一个学生记录 */
    struct node *next;          /* 指针字段：指向下一个节点 */
} NODE;

/* 显示链表 */
void show(NODE *head)
{
    for (NODE *p = head; p != NULL; p = p->next) {
        printf("%d %s %d\n", p->stu.id, p->stu.name, p->stu.score);
    }
}

/* 链表节点个数 */
int list_len(NODE *head)
{
    int c = 0;
    for (NODE *p = head; p != NULL; p = p->next) {
        c++;
    }
    return c;
}

int main(void)
{
    STU stu[100];
    STU alive[100];
    int dead[100] = {0};
    int n;
    int m = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }

    // TODO 1: 标记学号重复且成绩较低的记录

    // TODO 2: 收集留下的记录到 alive，按学号升序排序

    // TODO 3: 尾插法建链表

    NODE *head = NULL;

    printf("%d\n", list_len(head));
    show(head);

    return 0;
}
