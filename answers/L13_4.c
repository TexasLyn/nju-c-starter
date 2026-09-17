/* L13_4 参考答案 · 链表删除所有指定值的节点 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

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

NODE *delete_all(NODE *head, int x)
{
    NODE *cur = head;
    NODE *prev = NULL;

    while (cur != NULL) {
        if (cur->data == x) {
            NODE *toDelete = cur;

            if (prev == NULL) {
                head = cur->next;           /* 删的是第一个节点，要改 head */
            } else {
                prev->next = cur->next;     /* 前驱跳过 cur */
            }

            cur = cur->next;                /* 先取下一个，再释放 */
            free(toDelete);
            /* ⚠️ 这里不能动 prev：删除后 prev 仍是同一个前驱 */
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

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
