#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */


/* 链栈结构 */
typedef struct StackNode
{
        SElemType data;
        struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef struct
{
        LinkStackPtr top;
        int count;
}LinkStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  构造一个空栈S */
Status InitStack(LinkStack *S)
{
    // S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    // if (!S->top) { //若为NULL则内存申请失败
    //     return ERROR;
    // }
    S->top = NULL;
    S->count = 0;

    return OK;
}
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{ 
    return (S.count == 0 && S.top == NULL) ? TRUE : FALSE;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack *S)
{
    LinkStackPtr ptr;
    if (StackEmpty(*S)) {
        return OK;
    }
    do {
        ptr = S->top;
        S->top = ptr->next;
        free(ptr);
        S->count--;
    }while ((S->count) > 0);
    
    return OK;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{ 
    return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
    if (S.count == 0 || S.top == NULL) {
        return ERROR;
    } else {
        *e = S.top->data;
        return OK; 
    }
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr prt;
    prt = (LinkStackPtr)malloc(sizeof(StackNode));
    if (prt == NULL) {
        return ERROR;
    }

    prt->data = e;

    //若S为空栈，则第一次push，next为空。
    prt->next = (S->count == 0 && S->top ==NULL) ? NULL : S->top;

    S->top = prt;
    S->count++;

    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr ptr;

    if (StackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    ptr = S->top;
    S->top = ptr->next;
    free(ptr);
    S->count--;
    return OK;
}

Status StackTraverse(LinkStack S)
{
        LinkStackPtr p;
        p=S.top;
        while(p)
        {
                visit(p->data);
                p=p->next;
        }
        printf("\n");
        return OK;
}

int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        if (GetTop(s,&e)) {
            printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
        } else {
            printf("gettop error\n");
        }
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        return 0;
}