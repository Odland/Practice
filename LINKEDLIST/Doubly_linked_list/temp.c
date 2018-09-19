//插入数据
#include <stdio.h>
#include <stdlib.h>
struct LIST;
typedef struct LIST *Node;
typedef struct LIST list;
struct LIST {
    int num;
    Node Next;
};
int main (void)
{
    Node Head = (Node) malloc (sizeof (list));
    if (Head == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Head -> Next = NULL;
    Node L,T = Head;
    puts("请你输入建立的结点个数:");
    int i;
    scanf("%d",&i);
    int j;
    for (j = 1;j <= i;j++)
    {
	L = (Node) malloc (sizeof(list));
	if(L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}
	scanf("%d",&L -> num);
	L -> Next = T -> Next;
	T -> Next = L;

    }
    while(T -> Next != NULL)
    {
	printf("%d\t",T -> Next -> num);
	T = T -> Next;
    }
    putchar('\n');
    //puts("请输入你要插入的位置:");
    int mm;
    //scanf("%d",&mm);
    Node Tx = Head;
    int m = 0;
    while(Tx -> Next != NULL)
    {
	m++;
	Tx = Tx -> Next;
    }
    printf("%d\n",m);
    puts("请输入插入位置:");
    scanf("%d",&mm);
    
    
	if(mm > m)
	{
	    puts("插入点不合适太大!");
	    return 0;
	}
	if (mm <= 0)
	{
	    puts("插入点太小!");
	    return 0;
	}
	int ll;
	Node TT = Head;
	for(ll = 1;ll <= m;ll++)
	{
	    
	    if(mm == ll)
	    {
		Node L = (Node) malloc (sizeof (list));
		if (L == NULL)
		{
		    puts("内存分配失败!");
		    exit(1);
		}
		puts("请输入你要插入的元素:");
		//int l;
		scanf("%d",&L -> num);
		L -> Next = TT -> Next -> Next;
		TT -> Next -> Next = L;
		break;
	    }
	    
	    TT = TT -> Next;
	}
	
    
    puts("插入后的:");
    while(Head -> Next != NULL)
    {
	printf("%d\t",Head -> Next -> num);
	Head = Head -> Next;
    }
    putchar('\n');


    return 0;
}
