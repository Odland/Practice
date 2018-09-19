#include "list.h"
void Crea_list(Node Head,int num)
{
    int i;
    Node T = Head;
    Node L;
    for(i = 0;i < num;i++)
    {
	L = (Node)malloc(sizeof(list));
	if(L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}

	scanf("%d",&L -> num);
	L -> Next = T -> Next;
	T -> Next = L;
    
    }
    while(getchar()!='\n')
	continue;
}
int * Josep_list(Node Head,int *a,int Position,int num)
{
    Node Temp = Find_list(Head,Position);
    int l = Count_list(Head);
    //int h = l;
    //printf("这是计数%d",l);
    int nume = 0;
    Node L;
    while(l != 0)
    {
	int i = 1;	
	while(i != num)
	{
	    if(Temp -> Next == Head)
	    Temp = Head;
	    Temp = Temp -> Next;
	    if(Temp -> Next == Head)
		Temp = Head;
	    i++;
	    
	    
	}
	L = Temp -> Next;
	a[nume] = L -> num;
	nume++;
	Temp -> Next = Temp -> Next -> Next;
	free(L);
	l--;

	
    }
    /*int bb;
    int h=Count_list(Head);
    printf("\n这是%d\n",h);
    for(bb=0;bb<h;bb++)
    {
    printf("\n%d\n",a[bb]);
    }*/
    return a;

}
Node Find_list(Node Head,int Position)
{
    Node Temp = Head;
    int i = 0;
    while(i+1 != Position)
    {
	i++;
	Temp = Temp -> Next;
    }
    return Temp;

}
/*int Free_list(Node Temp,int num)
{
    int i=1;
    //int j = 0;
    while(i != num)
    {
	Temp = Temp -> Next;
	i++;
    }
    Node L = Temp -> Next;
    int j = Temp -> Next -> num;
    Temp -> Next = Temp -> Next -> Next;
    free(L);
    Node Temp = Find_list(Head,Position);
    while(Temp -> Next == Head)
    {
	puts("没找到请重新输入:");
	scanf("%d",Position);
	Temp = Find_list(Head,Position);
    }
    return j;
}*/
int Count_list(Node Head)
{
    int i=0;
    Node Temp = Head;
    while(Temp -> Next != Head)
    {
	i++;
	Temp = Temp -> Next;
    }
    return i;
}
void print_list(int *a,int l)
{
    int i;
    for(i=0;i<l;i++)
    {
	printf("%d\t",a[i]);
    }
    putchar('\n');
}
