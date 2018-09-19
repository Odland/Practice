#include "list.h"
int main (void)
{
    //创建一个头结点
    Node Head = (Node) malloc (sizeof(list));
    if(Head == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Head -> Next = NULL;
    Head -> Prec = NULL;
    //crea_Doubly_linked(Head);
    //这个返回的是尾结点
    Node Tail = crea_Doubly_linked(Head);
    //插入一个数据
    ins_list(Head,Tail);
    //按从前往后输出
    N_print_list(Head);
    //从后往前输出
    P_print_list(Tail);
    //计算长度
    printf("长度为%d\n",count_list(Head));
    Del_list(Head,Tail);
    N_print_list(Head);
    P_print_list(Tail);
    printf("长度为\n%d\n",count_list(Head));
    clean_list(Head,Tail);
    return 0;
}
