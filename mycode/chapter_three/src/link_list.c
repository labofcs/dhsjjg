#include "link_list.h"

/* 打印元素 */
status visit(elem_type e)
{
    printf("%d", e);
    return OK;
}

/* 打印线性表所有元素 */
status list_traverse(const link_list list)
{
    node *p;

    p = list->next;

    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");

    return OK;    
}

/* 初始化链式线性表 */
//TODO
status init_list(link_list *list)
{
    *list = malloc(sizeof(node));
    if (!(*list)) {
        return ERROR;
    }
    (*list)->next = NULL;

    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
status list_is_empty(const link_list list)
{
    if (list->next) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/* 初始条件：链式线性表L已存在。操作结果：将L重置为空表 */
//TODO
status clear_list(link_list *list)
{
    node *pnode, *tmp;

    pnode = (*list)->next;

    while (pnode) {
        tmp = pnode->next;
        free(pnode);
        pnode = tmp;
    }

    (*list)->next = NULL;

    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int list_length(const link_list list)
{
    int count;

    count = 0;
    node *pnode = list->next;

    while (pnode) {
        count++;
        pnode = pnode->next;
    }

    return count;
}

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
status get_elem(const link_list list, int counter, elem_type *e)
{
    int count = 1;
    node *pnode = list->next;

    while (pnode && count < counter) {
        count++;
        pnode = pnode->next;
    }
    if (!pnode || count > counter) {
        return ERROR;
    }
    *e = pnode->data;
    return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int get_elem_index(const link_list list, const elem_type *e)
{
    int index = 0;
    node *pnode = list->next;

    while (pnode) {
        index++;
        if (pnode->data == *e) {
            return index;
        }
        *pnode = *(pnode)->next;
    }
    return 0;
}

/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
status list_insert_elem(link_list *list, int index, elem_type e)
{
    int i;
    node *pnode, *newnode;

    pnode = (*list)->next;
    i = 1;

    while (pnode && (i < index)) {
        pnode = pnode->next;
        i++;
    }
    if (!p || i > index) {
        return ERROR;
    }
    newnode = (node*)malloc(sizeof(node));

    newnode->data = e;
    newnode->next = pnode->next;
    pnode->next = newnode;

    return OK;
}
