/*
 * L13_3 · 单向链表：创建 + 遍历 + 求和
 *
 * 【题目】（经典题）
 *   读入 n 个整数，用【尾插法】建立一个单向链表（保持输入顺序），
 *   然后：
 *       1. 输出链表的节点个数
 *       2. 输出所有节点的数据（用空格分隔）
 *       3. 输出所有数据的和
 *
 * 【输入格式】
 *   第一行：一个整数 n
 *   第二行：n 个整数
 *
 * 【输出格式】
 *   三行：
 *   第一行：节点个数
 *   第二行：所有数据，空格分隔
 *   第三行：所有数据的和
 *
 * 【样例】
 *   输入：
 *   5
 *   3 1 4 1 5
 *   输出：
 *   5
 *   3 1 4 1 5
 *   14
 *
 * 【这是链表的入门题，三块代码都要自己写】
 *
 * 【块 1：读入前先看看节点的定义】
 *   下面已经帮你写好了 NODE 的定义，你要看懂它：
 *
 *       typedef struct node {
 *           int data;                   (数据字段)
 *           struct node *next;          (指针字段，指向下一个节点)
 *       } NODE;
 *
 *   ⚠️ 自引用必须写 `struct node *next`，不能写 `NODE *next`。
 *      因为在结构体定义体内部，typedef 还没执行完，
 *      NODE 这个名字还不存在。这是本课最容易写错的地方之一。
 *
 * 【块 2：尾插法建链表】
 *
 *       NODE *head = NULL;
 *       NODE *tail = NULL;
 *
 *       for (int i = 0; i < n; i++) {
 *           int v;
 *           scanf("%d", &v);
 *
 *           NODE *p = (NODE *)malloc(sizeof(NODE));
 *           p->data = v;
 *           p->next = NULL;             (⚠️ 必须！)
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
 *   🔸 三个要点（都要记住）：
 *      a) 新节点创建后【立刻】p->next = NULL
 *      b) 第一个节点要特殊处理（head == NULL 时 head 和 tail 都指向它）
 *      c) 用 tail 记住尾巴，不用每次从头找
 *
 * 【块 3：遍历（计数和求和都在遍历里顺便算）】
 *
 *       int cnt = 0;
 *       int sum = 0;
 *
 *       for (NODE *p = head; p != NULL; p = p->next) {
 *           cnt++;
 *           sum = sum + p->data;
 *       }
 *
 *   ⚠️ 循环条件是 `p != NULL`，不是 `p->next != NULL`。
 *      写后者会漏掉最后一个节点。
 *
 * 【⚠️ 别忘了 #include <stdlib.h>】
 *   malloc 在里面，已经帮你 include 了。
 *
 * 【建议的练习方法】
 *   这道题不要直接看答案。先在纸上画出 5 个节点的链表图，
 *   标出 head、tail、p 分别指向哪里，每轮循环后它们怎么变。
 *   想清楚了再写代码。链表是"画出来就懂了"的东西。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

int main(void)
{
    int n;

    scanf("%d", &n);

    NODE *head = NULL;
    NODE *tail = NULL;

    int cnt = 0;
    int sum = 0;

    // TODO 1: 尾插法建链表（循环 n 次，每次读一个数做成节点接到尾巴后面）

    // TODO 2: 遍历链表，统计节点个数 cnt 和数据之和 sum

    printf("%d\n", cnt);

    // TODO 3: 再遍历一次，输出所有数据，用空格分隔，末尾换行
    //         （最后一个数后面不要多一个空格）

    printf("%d\n", sum);

    return 0;
}
