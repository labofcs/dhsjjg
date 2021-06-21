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

    
}