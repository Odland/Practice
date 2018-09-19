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
    int numeber;
    int Position,num;
    puts("请输入结点个数:");
    scanf("%d",&numeber);
    Crea_list(Head,numeber);
    int l = Count_list(Head);
    int *a = (int *) malloc (l * sizeof(int));
    puts("请输入位置和间隔:");
    scanf("%d%d",&Position,&num);
    a = Josep_list(Head,a,Position,num);
    print_list(a,l);
    if(Head -> Next == Head)
	puts("约瑟夫环正确!");
    return 0;
}
