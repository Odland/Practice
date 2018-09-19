#include "list.h"
//创建一个双向链表
Node crea_Doubly_linked(Node Head)
{
    Node L;
    Node T = Head;
    puts("开始创建双向链表:");
    puts("请输入创建链表结点的个数:");
    int num;
    scanf("%d",&num);
    int i;
    for (i = 0;i < num;i++)
    {
	L = (Node) malloc(sizeof(list));
	if(L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}
	scanf("%d",&L->num);
	L -> Next = T -> Next;
	T -> Next = L;
	Head -> Next -> Prec = T;
	if (L -> Next != NULL)
	{
	    L -> Next -> Prec = L;
	}
	
    }
    //建立一个尾结点
    while(1)
    {
	if (T -> Next == NULL)
	{
	    Node L = (Node) malloc (sizeof (list));
	    if(L == NULL)
	    {
		puts("内存分配失败!");
		exit(1);
	    }
	    L -> Next = NULL;
	    L -> Prec = T;
	    return L ;
	}
	T = T -> Next;
    }
}
//按后驱输出
void N_print_list(Node Head)
{
    Node T = Head;
    while(T -> Next != NULL)
    {
	printf("%d\t",T -> Next -> num);
	T = T -> Next;
    }
    putchar('\n');
}
//按前驱输出
void P_print_list(Node Tail)
{
   // printf("%d\t",Tail -> num);
    
    while(Tail -> Prec -> Prec != NULL)
    {
	//Tail = Tail -> Prec;
	printf("%d\t",Tail -> Prec -> num);
	Tail = Tail -> Prec;

    }
    putchar('\n');
}
//插入数据后插
void ins_list(Node Head,Node Tail)
{
    puts("请输入你要插入的位置:");
    int i;
    scanf("%d",&i);
    Node T = Head;
    int j;
    int count = count_list(Head);
    if (i > count)
    {
	puts("超出链表范围!");
	return;
    }
    if(i < 1)
    {
	puts("输入的数太小!");
	return;
    }
    for(j = 0;j < count;j++)
    {
	if(j+1 == i)
	{
	    Node L = (Node) malloc(sizeof(list));
	    if(L == NULL)
	    {
		puts("内存分配失败!");
		exit(1);
	    }
	    puts("请输入你要插入的元素:");
	    scanf("%d",&L -> num);
	    //在最后一个元素中插入
	    if(i == count)
	    {
		//Node l = T -> Next; 
		L -> Next = T -> Next -> Next;
		L -> Prec = T -> Next;
		T -> Next -> Next = L;
		//连接到尾结点
		Tail -> Prec = L;
		
		 
	    }
	    else
	    {
		L -> Next = T -> Next -> Next;
		L -> Prec = T -> Next -> Next -> Prec;
		T -> Next -> Next -> Prec = L;
		T -> Next -> Next = L;//这个放最后面
	    }
	    break;


	}
	T = T -> Next;	
    }

                                                                    
}
//链表计数
int count_list (Node Head)
{
    Node T = Head;
    int i = 0;
    while(T -> Next != NULL)
    {
	i++;
	T = T -> Next;
    }
    return i;
}
//按数据元素删除
void Del_list (Node Head,Node Tail)
{
    Node T = Head;
    Node Temp = Find_list(T);
    if(Temp == NULL)
    {
	puts("空表或者不存在!");
	return;
    }
    if(Temp -> Next == NULL)
    {
	Tail -> Prec = Temp -> Prec;
	Temp -> Prec -> Next = Temp -> Next;
	free(Temp);
    }
    else
    {
	Temp -> Next -> Prec = Temp -> Prec;
	Temp -> Prec -> Next = Temp -> Next;
	free(Temp);
    }
}
Node Find_list(Node Head)
{
    Node T = Head;
    int i;
    puts("请输入输入数据:");
    scanf("%d",&i);
    while(T -> Next != NULL && i != T -> Next -> num)
    {
	T = T -> Next;
    }
    return T -> Next;

}
void clean_list (Node Head,Node Tail)
{
    Node Temp;
    while(Head != NULL)
    {
	Temp = Head;
	Head = Head -> Next;
	free(Temp);
    }

    free(Tail);
    Tail = NULL;
    Head = NULL;
    
    puts("链表已清除");
}
