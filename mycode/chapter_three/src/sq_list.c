#include "sq_list.h"

/* 打印元素 */
status visit(elem_type e)
{
    printf("%d ", e);
    return OK;
}

/* 打印线性表所有元素 */
status list_traverse(const sq_list *list)
{
    int i;
    for (i = 0; i < list->length; i++) {
        visit(list->data[i]);
    }
    printf("\n");

    return OK;
}

/* 初始化线性表 */
status init_list(sq_list *list)
{
    memset(list, 0, sizeof(sq_list));
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
status list_is_empty(const sq_list *list)
{   
    if (list->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

//TODO: typedef 函数指针是否更合适？
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
status clear_list(sq_list *list)
{
    init_list(list);
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int list_length(const sq_list *list)
{
    return list->length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
status get_elem(const sq_list *list, int counter, elem_type *e)
{
    if (list->length == 0 || counter < 1 || counter > list->length) {
        return ERROR;
    } else {
        *e = list->data[counter - 1];
    }
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int get_elem_index(const sq_list *list, const elem_type *e)
{
    int counter;

    counter = 0;

    if (list->length == 0) {
        return 0;
    }
    for (; counter < (list->length); counter++) {
        if (list->data[counter] == *e) {
            return (counter + 1);
        }
    }
    return 0;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
/* 即a = data[i-1], b =data[i] 变成 a = data[i-1] e = data[i], b = data[i+1]*/
status list_insert_elem(sq_list *list, int index, elem_type e)
{
    int i;
    /* 顺序线性表已经满 */
    if (list->length == MAXSIZE) {
        return ERROR;
    }
    /* 插入位置小于1或者大于当前线性表长度*/
    if (index < 1 || index > (list->length + 1)) {
        return ERROR;
    }

    /* 当插入位置小于等于线性表长度时，需对插入位原元素做向后位移操作 */
    if (index <= list->length) {
        /*线性表最后一个元素下标*/
        i = (list->length) - 1;

        /* 倒推写法略难理解，注明下临界值
        新线性表在当前最右端元素下标应为list->length,
        index-1（插入位）的右侧数据位(index)应放入原index-1数据
        即需执行
        list->data[index - 1] = list->data[index];
        */    
        for (; i >= (index - 1); i--) {
            list->data[i + 1] = list->data[i];
        }

        /* 取巧写法右移长度应为(list->length) - (index - 1) */
        // memmove(&(list->data[index]), &(list->data[index - 1]),
        //         sizeof(elem_type) * ((list->length) - (index - 1)));  
    }
    list->data[index - 1] = e;
    list->length++;

    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
status list_delete_elem(sq_list *list, int index, elem_type *e)
{
    int i;
    //示例代码中检测原线性表是否为空，在我看来无需判断，
    //因为当线性表为空时，下面的检测也不会通过。

    /* 删除位置小于1或大于当前线性表长度 */
    if (index < 1 || index > list->length) {
        return ERROR;
    }

    *e = list->data[index - 1];

    if (index < list->length) {     /* 如果删除不是最后位置 */
        for (i = index; i < list->length; i++) {
            list->data[i - 1] = list->data[i];
        }
    }
    list->length--;

    return OK;
}

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void union_list(sq_list *list_a, const sq_list *list_b)
{
    int list_a_len, list_b_len, index;
    status is_ok;
    elem_type tmp;
    list_a_len = list_a->length;
    list_b_len = list_b->length;
    for (index = 1; index < list_b_len; index++) {
        get_elem(list_b, index, &tmp);
        if (!get_elem_index(list_a, &tmp)) {
            is_ok = list_insert_elem(list_a, ++list_a_len, tmp);
            if (!is_ok) {
                printf("error list_a is full!\n");
            }
        }
    }
}
