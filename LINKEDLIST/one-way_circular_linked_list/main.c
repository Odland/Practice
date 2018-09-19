#include "list.h"
int main (void)
{
    Node Head = (Node)malloc(sizeof(list));
    if(Head == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Head -> Next = Head;
    Crea_list(Head);
    Ins_list(Head);
    print_list(Head);
    Del_list(Head);
    print_list(Head);
    return 0;
}
