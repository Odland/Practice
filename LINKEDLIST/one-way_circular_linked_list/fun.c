#include "list.h"
//验证是否为空
void Isempty(Node Head)
{
    if(Head -> Next == Head)
	puts("链表为空!");
}
//创建链表
void Crea_list(Node Head)
{
    Node T = Head;
    puts("输入建立的结点的个数：");
    int i;
    scanf("%d",&i);
    int j;
    Node L;
    for(j = 0;j < i;j++)
    {
	L = (Node) malloc (sizeof(list));
	if(L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}
	puts("请输入元素:");
	scanf("%d",&L -> num);
	while(getchar() != '\n')
	    continue;
	L -> Next = T -> Next;
	T -> Next = L;
    }
}
//顺序输出
void print_list(Node Head)
{
    Node T = Head;
    while(T -> Next != Head)
    {
	printf("%d\t",T -> Next -> num);
	T = T -> Next;
    }
    putchar('\n');
}
//后插
void Ins_list(Node Head)
{
    //Node T = Head;
    Node Temp = Elem_Find_list(Head);
    Temp = Temp -> Next;
    if(Temp == Head)
    {
	puts("未找到不存在的!");
	return;
    }
    Node L = (Node)malloc(sizeof(list));
    if(L == Head)
    {
	puts("内存分配失败!");
	exit(1);
    }
    puts("请输入你要插入的元素:");
    scanf("%d",&L->num);
    L -> Next = Temp -> Next;
    Temp -> Next = L;
    
}
//删除
void Del_list(Node Head)
{
    Node Temp = Elem_Find_list(Head);
    Node L = Temp -> Next;
    Temp -> Next = Temp -> Next -> Next;
    free(L);
}
//按位置查找
Node Posi_Find_list(Node Head)
{
    Node T = Head;
    int i;
    puts("请输入位置:");
    scanf("%d",&i);
    int j = 0;
    while(T -> Next != Head && j + 1 != i )
    {
	j++;
	T = T -> Next;

    }
    return T ;

}
//按元素查找
Node Elem_Find_list(Node Head)
{
    Node T = Head;
    puts("请输入元素:");
    int i;
    scanf("%d",&i);
    while(T -> Next != Head && i != T -> Next -> num)
    {
	T = T -> Next;
    }
    return T ;
}
