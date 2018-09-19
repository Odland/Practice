#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//创建一个链表
List Create_list(List header)
{
    int d;
    List L;
    puts("请你开始输入数据,输入整数以外的数结束输入:");
    //头插法
    /*while(1)
    {
    //List L = (List) malloc(sizeof(struct Node);
	if(scanf("%d",&d))
	{
	    L = (List) malloc(sizeof(struct Node));//分配结构所需要的内存
	    L->data = d;//分配成功将数据赋给结构里的数据变量
	    L -> Next = header->Next;//NULL指针往后挪
	    header->Next = L;//将下一个结构的地址给上一个结构的地址

	}
	else
	    break;
    }*/
    //尾插法
    if(scanf("%d",&d))
    {
	List e;
	L=(List) malloc (sizeof(struct Node));
	L->data = d;
	L->Next = header->Next;
	header->Next = L;
	e=L;
//	puts("继续输入:");
	while(scanf("%d",&d))
	{
	    L=(List) malloc (sizeof(struct Node));
	    L->data=d;
	    e->Next=L;
	    L->Next=NULL;
	    e=L;
	}
    }
    return header;
    //可以输出数据
    /*
    Position L1 = header->Next;
    while(L1 != NULL)
    {
	printf("%d\t",L1->data);
	L1=L1->Next;
    }*/

}
//输出链表的数据
void Print_list(List header)
{
    List L = header->Next;
    while(L != NULL)
    {
	printf("%d\t",L->data);
	L = L->Next;
    }
    putchar('\n');
}
//按值查找
void Find(Ele_Type x,List header)
{
    int i = 1;
    Position P = header;
    while(P -> Next != NULL && P -> Next -> data != x)
    {
	P = P -> Next;
	i++;
    }
    if(Isempty(P))
    {
	puts("空表或者不存在");
	return;
    }
    else
    {
	printf("元素的位置在%d\n",i);
    }
}


Position find_previous(List header,Ele_Type i)//找到目标元素的前驱
{
    List temp = header;
    while(temp -> Next != NULL && temp -> Next -> data != i)
    {
	temp = temp -> Next;
    }
    return temp;
}

//判断链表是否为空或者判断当前位置是否是链表的末尾
int Isempty (List P)
{
    return P->Next == NULL;
}
//插入数据
void Ins_list(List P,Ele_Type i,int j)
{

    List temp = P;
    List L;
    int num = 0;
    if(Isempty(temp))
    {
	if(j == 0)
	{
	    L = (List) malloc (sizeof (struct Node));
	    if(L != NULL)
	    {
		L -> data = i;
		L -> Next = temp -> Next;
		temp -> Next = L;
	    }
	    else
	    {
		puts("分配内存失败!");
		return;
	    }
	}
	else
	{
	    puts("插入点不合适!");
	    return;
	}
    }
    else
    {
	while(num < j && temp)
	{
	    temp = temp->Next;
	    num++;
	}
	if(j < 1 || num < j || (num == j && !temp))
	{
	    puts("请重新输入插入的位置!");
	    return;
	}
	else
	{
	    L = (List) malloc (sizeof(struct Node));
	    if(L != NULL)
	    {
		L -> data = i;
		L -> Next = temp -> Next;
		temp -> Next = L;
	    }
	    else
	    {
		puts ("分配内存失败!");
		return;
	    }
	  
	}

    }
}
//删除链表
void Del_list(List L,Ele_Type n)
{
    //List temp = L;
    List P;
    Position s = find_previous(L,n);//调用find_previous()函数返回目标元素的前驱
    if(s -> Next == NULL)
    {
	puts("空表或者不存在这个元素");
    }
    else 
    {
	P = s -> Next;
	s -> Next = s -> Next -> Next;//P -> Next
	free(P);
    }
}
void Clea_list(List L)//清除链表
{
    Position temp = L;
    Position P;
    while(temp -> Next != NULL)
    {
	P=temp -> Next;
	temp -> Next=temp->Next -> Next;//一次将头结点后面的指针挪到头结点的Next
	free(P);

    }
}

void display(List header)//菜单函数
{
    int number;
    int n2,del;
    Ele_Type n1;
    Ele_Type fin;;
    while(number=get_inter())
    {

	switch(number)
	{
	    case 1 :
		Create_list(header);
		Print_list(header);
		while(getchar() != '\n')
		    continue;
		break;
	    case 2 :
		
		puts("请输入你想要插入的元素和位置");
		scanf("%d%d",&n1,&n2);
		
		Ins_list(header,n1,n2);

		Print_list(header);
		while(getchar() != '\n')
		    continue;
		break;
	    case 3 :
		puts("请你输入你想要删除的元素");
		
		scanf("%d",&del);
		while(getchar() != '\n')
		    continue;
		Del_list(header,del);
		Print_list(header);
		
		break;
	    case 4 :
		puts("请输入你想要查找的元素");

		scanf("%d",&fin);
		while(getchar() != '\n')
		    continue;
		Find(fin,header);

		break;
	    case 5 :
		Clea_list(header);
		Print_list(header);

	
	    default :
		puts("输入有误");
		break;
	

	}
    }

}
int get_inter(void)
{
    int i;
    puts("1 创建链表\t2 插入元素\t3 删除元素\t4 查找元素\t5 清除链表");
    while (scanf ("%d",&i) != 1)
    {
		while(getchar() != '\n')
			continue;
		puts("输入有误，重新输入:");
    }
    return i;
}

