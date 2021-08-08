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

/* 顺序栈结构 */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* 用于栈顶指针 */
}SqStack;

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

/*  构造一个空栈S */
Status InitStack(SqStack *S)
{ 
    S->top = -1;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{ 
    S->top = -1;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{ 
    if (S.top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{ 
    return (S.top + 1);
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S,SElemType *e)
{
    if (S.top != -1) {
        *e = S.data[S.top];
        return OK;
    } else {
        return ERROR;
    }
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S,SElemType e)
{
    if (S->top < MAXSIZE - 1) {
        S->top++;
        S->data[S->top] = e;
        return OK;
    } else {
        return ERROR;
    }
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if (S->top > -1) {
        *e = S->data[S->top];
        S->top--;
        return OK;
    } else {
        return ERROR;
    }
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(SqStack S)
{
    int count;
    count = 0;
    while (count <= S.top) {
        visit(S.data[count]);
        count++;
    }
    printf("\n");

    return OK;
}

int main()
{
        int j;
        SqStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        
        return 0;
}

