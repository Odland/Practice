#include "ListAndStack.h"
int main(void)
{
    List Head = Init_List();
    Stack S = Init_Stack();
    int num,Elem;
    int i=0;

    puts("请你输入结点的数量:");
    scanf("%d",&num);
    while(i<num)
    {
	puts("请你输入元素:");
	scanf("%d",&Elem);
	Crea_List(Head,Elem);
	i++;
    }
    puts("现在的链表的元素的顺序是这样的:");
    PrintList(Head);
    Print_Node(Head,S);
    Pop_List(Head,S);
    puts("逆置后的:");
    PrintList(Head);
    
    return 0;
}
