/* L13_1 参考答案 · 联系人数组的管理 */

#include <stdio.h>
#include <string.h>

typedef struct {
    int  id;
    char name[20];
    char sex[8];
} PS;

void display(PS *ps, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d %s %s\n", ps[i].id, ps[i].name, ps[i].sex);
    }
}

int delete_by_id(PS *ps, int n, int id)
{
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (ps[i].id != id) {
            ps[k] = ps[i];          /* 结构体整体赋值，不用逐字段复制 */
            k++;
        }
    }

    return k;
}

void sort_by_id(PS *ps, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ps[i].id > ps[j].id) {
                PS t = ps[i];       /* 整体拷贝交换，比逐个字段简单得多 */
                ps[i] = ps[j];
                ps[j] = t;
            }
        }
    }
}

int main(void)
{
    PS ps[100];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
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
