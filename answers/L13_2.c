/* L13_2 参考答案 · 结构体数组建链表（按学号升序，同号保留高分） */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int  id;
    char name[20];
    int  score;
} STU;

typedef struct node {
    STU stu;
    struct node *next;
} NODE;

void show(NODE *head)
{
    for (NODE *p = head; p != NULL; p = p->next) {
        printf("%d %s %d\n", p->stu.id, p->stu.name, p->stu.score);
    }
}

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

    /* 第一步：标记学号重复且成绩较低的记录 */
    for (int i = 0; i < n; i++) {
        if (dead[i]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (dead[j]) {
                continue;
            }
            if (stu[i].id == stu[j].id) {
                if (stu[i].score >= stu[j].score) {
                    dead[j] = 1;            /* j 的成绩不高，丢掉 j */
                } else {
                    dead[i] = 1;            /* i 的成绩不高，丢掉 i */
                    break;                  /* i 已经废了，不用再看 */
                }
            }
        }
    }

    /* 第二步：收集留下的记录 */
    for (int i = 0; i < n; i++) {
        if (!dead[i]) {
            alive[m] = stu[i];
            m++;
        }
    }

    /* 第三步：按学号升序排序（结构体整体赋值交换） */
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (alive[i].id > alive[j].id) {
                STU t = alive[i];
                alive[i] = alive[j];
                alive[j] = t;
            }
        }
    }

    /* 第四步：尾插法建链表 */
    NODE *head = NULL;
    NODE *tail = NULL;

    for (int i = 0; i < m; i++) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->stu = alive[i];
        p->next = NULL;

        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    printf("%d\n", list_len(head));
    show(head);

    return 0;
}
