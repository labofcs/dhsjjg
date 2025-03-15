#include "sq_list.h"
#include <stdio.h>
#include <string.h>
status visit(elem_type e){
    printf("%d",e);
    return OK;
}

bool list_is_empty(const sq_list *list)
{
    return (list->length == 0) ? true : false;
}

status list_traverse(const sq_list *list)
{
    if (list_is_empty(list) != true) {
        for (int i = 0; i < list->length; i++) {
            visit(list->data[i]);
        }
        return OK;
    } else {
        printf("this list is empty!\n");
        return ERROR;
    }
}

static status initialize_sq_list(sq_list *list) {
    memset(list->data, 0, sizeof(elem_type) * MAXSIZE);
    list->length = 0;
    return OK;
}

status init_list(sq_list *list)
{
    return list == NULL ? ERROR : initialize_sq_list(list);
}
status clear_list(sq_list *list)
{
    return list == NULL ? ERROR : initialize_sq_list(list);
}

status get_elem(const sq_list *list, int count, elem_type *e)
{
    if (list == NULL || count <= 0 || count > list->length) {
        return ERROR;
    } else {
        *e = list->data[count - 1];
        return OK;
    }
}

int locate_elem(const sq_list *list, const elem_type *e)
{
    if (list == NULL || e == NULL || list->length == 0) {
        return ERROR;
    }
    for (int i = 0; i < list->length; i++) {
        if(list->data[i] == *e) {
            return i+1;
        }
    }
    return ERROR;
}
status insert_elem(sq_list *list, int count, elem_type *e)
{
    if (list == NULL || count < 1 || count > list->length + 1 || list->length == MAXSIZE) {
        return ERROR;
    }
    if (count != list->length + 1) {
        /* 防御性编程习惯，不应使用注解内的写法，存在数组越界的风险 */
        // for (int i = list->length; i>= count - 1; i--) {
        //     list->data[i] = list->data[i - 1];
        // }
        for (int i = list->length - 1; i >= count - 1; i--) {
            list->data[i + 1] = list->data[i];
        }

    }
    list->data[count - 1] = *e;
    list->length++;

    return OK;
}
status delete_elem(sq_list *list, int count, elem_type *e) {
    if (list == NULL || count < 1 || count > list->length) {
        return ERROR;
    }
    *e = list->data[count - 1];
    if (count != list->length) {
        for (int i = count; i < list->length; i++) {
            list->data[i - 1] = list->data[i];
        }
    }
    list->length--;

    return OK;
}

int get_list_length(const sq_list *L) {
    return L->length;
}