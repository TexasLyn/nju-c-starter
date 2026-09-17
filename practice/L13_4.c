/*
 * L13_4 · 链表删除节点
 *
 * 【题目】（经典题）
 *   读入 n 个整数用尾插法建链表，然后删除链表中【所有值等于 x 的节点】，
 *   输出删除后的链表。
 *
 * 【输入格式】
 *   第一行：一个整数 n
 *   第二行：n 个整数
 *   第三行：一个整数 x（要删除的值）
 *
 * 【输出格式】
 *   第一行：删除后的节点个数
 *   第二行：删除后的数据，空格分隔（如果为空则输出空行）
 *
 * 【样例】
 *   输入：
 *   6
 *   1 2 3 2 5 2
 *   2
 *   输出：
 *   3
 *   1 3 5
 *
 *   输入：
 *   3
 *   7 7 7
 *   7
 *   输出：
 *   0
 *
 * 【删除节点的核心难点：要记住"前驱"】
 *
 *   要删掉一个节点，就得让它的【前驱】跳过它：
 *
 *       删除前：  prev ──→ cur ──→ next
 *       删除后：  prev ──────────→ next
 *
 *   所以遍历的时候需要【两个指针】，一个指当前，一个指上一个。
 *
 * 【框架：遍历 + 两个指针】
 *
 *       NODE *cur = head;
 *       NODE *prev = NULL;
 *
 *       while (cur != NULL) {
 *           if (cur->data == x) {
 *               (要删 cur)
 *               NODE *toDelete = cur;
 *
 *               if (prev == NULL) {
 *                   (cur 是第一个节点，要改 head)
 *                   head = cur->next;
 *               } else {
 *                   prev->next = cur->next;     (前驱跳过 cur)
 *               }
 *
 *               cur = cur->next;                (cur 前进（用删之前的 next）)
 *               free(toDelete);                 (释放内存)
 *               (⚠️ 这里【不要】改 prev！因为 prev 还是同一个前驱)
 *           } else {
 *               (不删，两个指针都前进)
 *               prev = cur;
 *               cur = cur->next;
 *           }
 *       }
 *
 * 【⚠️ 三个最容易错的地方】
 *
 *   1. 删除时【不要更新 prev】。
 *      因为删除后，prev 的下一个变成了 cur 的下一个，
 *      prev 还是"当前节点的前驱"，位置没变。
 *      如果这里写了 prev = cur，prev 就指向了被删的节点，
 *      后面再删一个就会出错（甚至连着删不掉）。
 *
 *   2. cur = cur->next 必须在 free 之前取。
 *      顺序不能反：
 *          NODE *toDelete = cur;
 *          cur = cur->next;        (✓ 先取下一个)
 *          free(toDelete);         (再释放)
 *
 *      如果先 free(cur) 再读 cur->next，就是读已经释放的内存
 *      （use-after-free），可能崩溃或者读到垃圾值。
 *
 *   3. 删头节点时要改 head。
 *      这就是 `if (prev == NULL)` 那个分支的作用。
 *      忘了这个分支，头节点删不掉。
 *
 * 【⚠️ 关于连续多个相同值】
 *   样例 2 是 [7, 7, 7]，要全删掉。
 *   走一遍：
 *       cur=节点1(7), prev=NULL
 *           要删 → head = 节点2, cur = 节点2, free(节点1), prev 不变(NULL)
 *       cur=节点2(7), prev=NULL
 *           要删 → head = 节点3, cur = 节点3, free(节点2), prev 不变(NULL)
 *       cur=节点3(7), prev=NULL
 *           要删 → head = NULL, cur = NULL, free(节点3)
 *       cur == NULL，结束
 *   结果 head = NULL，节点数 0 ✓
 *
 *   注意 prev 一直是 NULL，因为删的始终是第一个节点。
 *   这说明"删除时不更新 prev"这条规则是对的。
 *
 * 【为什么用 free】
 *   释放被删节点的内存。C 没有垃圾回收，不释放就泄漏了。
 *   练习里可以省略，但养成习惯是好的。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

/* 尾插法建链表 */
NODE *create(int n)
{
    NODE *head = NULL;
    NODE *tail = NULL;

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);

        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = v;
        p->next = NULL;

        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    return head;
}

/* 删除所有值为 x 的节点，返回新的 head */
NODE *delete_all(NODE *head, int x)
{
    // TODO
    return head;
}

int main(void)
{
    int n, x;

    scanf("%d", &n);

    NODE *head = create(n);

    scanf("%d", &x);

    head = delete_all(head, x);

    int cnt = 0;
    for (NODE *p = head; p != NULL; p = p->next) {
        cnt++;
    }
    printf("%d\n", cnt);

    int first = 1;
    for (NODE *p = head; p != NULL; p = p->next) {
        if (!first) {
            printf(" ");
        }
        printf("%d", p->data);
        first = 0;
    }
    printf("\n");

    return 0;
}
