#include "sq_list.h"

int main()
{
        
    sq_list L;
	sq_list Lb;
    
    elem_type e;
    status i;
    int j,k;
    i = init_list(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i = list_insert_elem(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    list_traverse(&L);

    printf("L.length=%d \n",L.length);
    i = list_is_empty(&L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i = clear_list(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i = list_is_empty(&L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            list_insert_elem(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    list_traverse(&L);

    printf("L.length=%d \n",L.length);

    list_insert_elem(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    list_traverse(&L);
    printf("L.length=%d \n",L.length);

    get_elem(&L, 5, &e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            
            k=get_elem_index(&L, &j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=list_length(&L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            
            i = list_delete_elem(&L, j, &e);/* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    list_traverse(&L);

    j=5;
    list_delete_elem(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    list_traverse(&L);

	//构造一个有10个数的Lb
    i = init_list(&Lb);
    for(j=6;j<=15;j++)
            i = list_insert_elem(&Lb,1,j);

    union_list(&L,&Lb);

	printf("依次输出合并了Lb的L的元素：");
    list_traverse(&L);

    return 0;
}

