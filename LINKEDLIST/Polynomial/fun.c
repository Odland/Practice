#include<stdio.h>
#include<stdlib.h>
#include"list.h"
//创建一元多项式
void crea_list(Node Head)
{
   Node E = Head;
    
    Node L = (Node) malloc (sizeof(list)); 
    // L -> Next = Head -> Next;
    // Head -> Next = L;
    if (L == NULL)
    {
	puts("内存分配失败！");
	exit(1);
    }
    puts("请输入一个多项式，输入q时结束输入:");
    puts("请输入系数：");
    if(scanf("%d",&L -> Coe) != 1)
	return;
    puts("请输入指数：");
    if(scanf("%d",&L -> Expo) != 1)
	return;
    E -> Next = L;
    L -> Next = NULL;
    Node e = L;
    while(1)
    {
	L = (Node) malloc (sizeof(list));
	if(L == NULL)
	{
	    puts("分配内存失败!");
	    exit(1);
	}
	puts("请输入系数：");
	if(scanf("%d",&L -> Coe) != 1)
	    break;
	puts("请输入指数:");
	if(scanf("%d",&L -> Expo) != 1)
	    break;
	e -> Next = L;
	L -> Next = NULL;
	e = L;

    }
}
//输出一元多项式
void print_list(Node Head)
{
    Node E = Head -> Next;
    while (E!= NULL)
    {
    printf("%dx^%d\t",E -> Coe,E -> Expo);
    E = E -> Next; 
    }
    printf("\n");
    clean_list(Head);
}
//加法
Node add_list (Node Head,Node Head1)
{
    Node Head2 = (Node) malloc (sizeof(list));
    if(Head2 == NULL)
    {
	puts("Head2内存分配失败！");
	exit(1);
    }
    Head2 -> Next =  NULL;
    Node T2 = Head2;
   Node T = Head;
   Node T1 = Head1;
   while(1)
   {
    if(T -> Next != NULL && T1 -> Next != NULL)
    {
	if(T -> Next -> Expo == T1 -> Next -> Expo)
	{
	    Node L = (Node) malloc (sizeof(list));
	    if(L == NULL)
	    {
		puts("内存分配失败！");
		exit(1);
	    }
	    L -> Coe = T -> Next -> Coe + T1 -> Next -> Coe;
	    L -> Expo = T -> Next -> Expo;
	    L -> Next = T2 -> Next;
	    T2 -> Next = L;
	    T = T -> Next;
	    T1 = T1 -> Next;

	}
	else if (T -> Next -> Expo > T1 -> Next -> Expo)
	{
	    Node L = (Node) malloc (sizeof(list));
	    if(L == NULL)
	    {
		puts("内存分配失败！");
		exit(1);
	    }
	    L -> Coe = T -> Next -> Coe;
	    L -> Expo = T -> Next -> Expo;
	    L -> Next = T2 -> Next;
	    T2 -> Next = L;//连接到T2
	    T = T -> Next;
	    L = (Node) malloc (sizeof(list));
	    if(L == NULL)
	    {
		puts("内存分配失败!");
		exit(1);
	    }
	    L -> Coe = T1 -> Next -> Coe;
	    L -> Expo = T1 -> Next -> Expo;
	    L -> Next = T2 -> Next;
	    T2 -> Next = L;
	    T1 = T1 -> Next;

	}
	else if(T -> Next -> Expo < T1 -> Next -> Expo)
	{
	    Node L = (Node) malloc(sizeof(list));
	    if(L == NULL)
	    {
		puts("分配内存失败！");
		exit(1);
	    }
	    L -> Coe = T1 -> Next -> Coe;
	    L -> Expo = T1 -> Next -> Expo;
	    L -> Next = T2 -> Next;
	    T2 -> Next = L;
	    T1 = T1 -> Next;
	    L = (Node) malloc(sizeof(list));
	    if(L == NULL)
	    {
		puts("分配内存失败！");
		exit(1);
	    }
	    L -> Coe = T -> Next -> Coe;
	    L -> Expo = T -> Next -> Expo;
	    L -> Next = T2 -> Next;
	    T2 -> Next = L;
	    T = T -> Next;

	}
    }
    else if (T -> Next == NULL && T1 -> Next != NULL)
    {
	Node L = (Node) malloc (sizeof(list));
	if (L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}
	L -> Coe = T1 -> Next -> Coe;
	L -> Expo = T1 -> Next -> Expo;
	L -> Next = T2 -> Next;
	T2 -> Next = L;
	T1 = T1 -> Next;

    
    }
    else if (T -> Next != NULL && T1 -> Next == NULL)
    {
	Node L = (Node) malloc (sizeof(list));
	if (L == NULL)
	{
	    puts("内存分配失败!");
	    exit(1);
	}
	L -> Coe = T -> Next -> Coe;
	L -> Expo = T -> Next -> Expo;
	L -> Next = T2 -> Next;
	T2 -> Next = L;
	T = T -> Next;
    }
    else 
	break;
   }
    return Head2;

}
Node Mult (Node Head,Node Head1)
{
    Node Head2,T2;
    Node T = Head -> Next,T1 = Head1 -> Next;
    Head2 = (Node) malloc(sizeof(list));
    if(Head2 == NULL)
    {
	puts("内存分配为失败!");
	exit(1);
    }
    Head2 -> Next = NULL;
    T2 = Head2 -> Next;
    while(T != NULL)
    {
	Node L;
	while(T1 != NULL)
	{
	    L = (Node)malloc(sizeof(list));
	    if(L == NULL)
	    {
		puts("内存分配失败!");
		exit(1);
	    }
	    L -> Coe = T -> Coe * T1 -> Coe;
	    L -> Expo = T -> Expo + T1 -> Expo;
	    L -> Next = T2;
	    T2 = L;
	    T1 = T1 -> Next;

	}
	T1 = Head1 -> Next;
	T = T -> Next;
    }
    Head2 -> Next = T2;
    return Head2;
    

}
void clean_list(Node Head)
{
    Node T = Head;
    Node TT;
    while(T != NULL)
    {
	TT = T;
	T = T -> Next;
	free(TT);
    }
    puts("内存已释放！");
}
