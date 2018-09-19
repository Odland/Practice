#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int main (void)
{
    //建立头结点
    Node Head = (Node) malloc (sizeof (list));
    if(Head == NULL)
    {
	puts("Head内存分配失败!");
	exit(1);
    }
    Head -> Next = NULL;
    Node Head1 = (Node) malloc (sizeof(list));
    if(Head1 == NULL)
    {
	puts("Head1分配内存失败!");
	exit(1);
    }
    puts("创建第一个多项式:");
    crea_list (Head);
    //print_list(Head);
    while(getchar() != '\n')
	continue;
    puts("创建第二个多项式:");
    crea_list(Head1);
    //print_list(Head1);
    while(getchar() != '\n')
	continue;
    puts("和为:");
    print_list(add_list(Head,Head1));
    puts("积为:");
    print_list(Mult(Head,Head1));
    clean_list(Head);
    clean_list(Head1);
    return 0;
}
