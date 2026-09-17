/* L13_3 参考答案 · 链表创建 + 遍历 + 求和 */

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

    /* 尾插法建链表 */
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);

        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = v;
        p->next = NULL;                 /* 新节点的 next 必须先置空 */

        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    /* 遍历一次：计数 + 求和 */
    for (NODE *p = head; p != NULL; p = p->next) {
        cnt++;
        sum = sum + p->data;
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

    printf("%d\n", sum);

    return 0;
}
