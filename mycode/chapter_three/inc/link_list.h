
#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   

#include "math.h"  
#include "time.h"


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20              /* 存储空间初始分配量 */

typedef int status;             /* status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int elem_type;          /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct node
{
    elem_type data;
    struct node *next;
}node;

typedef struct node *link_list; /* 定义link_list */

/* 打印元素 */
status visit(elem_type e);

/* 打印线性表所有元素 */
status list_traverse(const link_list list);

/* 初始化链式线性表 */
//TODO
status init_list(link_list *list);

/* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
status list_is_empty(const link_list list);

/* 初始条件：链式线性表L已存在。操作结果：将L重置为空表 */
//TODO
status clear_list(link_list *list);

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int list_length(const link_list list);

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
status get_elem(const link_list list, int counter, elem_type *e);

/* 初始条件：链式线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int get_elem_index(const link_list list, const elem_type *e);

/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
status list_insert_elem(link_list *list, int index, elem_type e);

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
status list_delete_elem(link_list *list, int index, elem_type *e);

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
// void union_list(sq_list *list_a, const sq_list *list_b);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void create_list_head(link_list *list, int n);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void create_list_tail(link_list *list, int n);

#endif  /* link_list.h  */