#include "static_link_list.h"

Status visit(ElemType c)
{
    printf("%c", c);
    return OK;
}

//数组的第一个元素的cur（即arr[0].cur）用来存放备用空间第一个节点的下标（即下一个将被填充数据数组元素的下标）
//数组的最后一个元素的cur（即arr[MAXSIZE -1 ].cur）用来存放链表的第一个节点下表，该位置作用为头结点。
Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1 ; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0; /* 目前静态链表为空，最后一个元素的cur为0 */

    return OK;
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SSL(StaticLinkList space)
{
    int i = space[0].cur;
    //TODO:这里判断i的值为了之后代码做静态链表满的时候的扩充
    if (i) {
        space[0].cur = space[i].cur;
    }
    return i;
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L)
{
    int count = 0;
    int i = L[MAXSIZE - 1].cur;
    
    while (i) { // i != 0时意味着没有遍历到最后一个节点；
        i = L[i].cur;
        count++;
    }

    return count;
}

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int count, length, index, pre_index;

    length = ListLength(L);
    count = 1;
    pre_index = MAXSIZE - 1;
    //???? 为啥源码中是    if (i < 1 || i > ListLength(L) + 1)
    // 当链表长度为0，插入第一个1元素，则我写的代码不能通过。
    // if (i< 1 || i > length) {
    if (i< 1 || i > length + 1) {
        return ERROR;
    }
    index = Malloc_SSL(L);
    if (index) {
        L[index].data = e;

        for (; count < i; count++) {
            pre_index = L[pre_index].cur;
        }

        L[index].cur = L[pre_index].cur;
        L[pre_index].cur = index;

        return OK;
    }

    return ERROR;
}
/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i)
{
    int pre_index, index, count, length;

    pre_index = MAXSIZE - 1;
    count = 1;
    length  = ListLength(L);
    if (i < 1 || i> length) {
        return ERROR;
    }
    while (count < i) {
        pre_index = L[pre_index].cur;
        count++;
    }
    index = L[pre_index].cur;
    L[pre_index].cur = L[index].cur;
    
    Free_SSL(L, index);

    return OK;
}


Status ListTraverse(StaticLinkList L)
{
    int  p;

    p = L[MAXSIZE -1].cur;

    while (p) {
        visit(L[p].data);
        p = L[p].cur;

    }
    return OK;
}
