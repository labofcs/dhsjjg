#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#include <stdbool.h>

#define MAXSIZE 20  /* 存储空间初始分配量 */
typedef int elem_type;  /* ElemType类型根据实际情况而定，这里假设为int */
typedef bool status;    /* status是函数的类型,其值是函数结果状态代码，如OK等 */ 
#define OK true
#define ERROR false

/* 定义一个线性表 */
typedef struct {
    elem_type data[MAXSIZE];
    int length;  /* 线性表当前长度 */
}sq_list;

/* 打印元素 */
status visit(elem_type e);
/* 打印线性表所有元素 */
status list_traverse(const sq_list *list);
/* 初始化线性表 */
status init_list(sq_list *list);
bool list_is_empty(const sq_list *list);
status clear_list(sq_list *list);
status get_elem(const sq_list *list, int count, elem_type *e);
int locate_elem(const sq_list *list, const elem_type *e);
status insert_elem(sq_list *list, int count, elem_type *e);
status delete_elem(sq_list *list, int count, elem_type *e);
int get_list_length(const sq_list *L);

#endif /* __SQ_LIST_H__ */