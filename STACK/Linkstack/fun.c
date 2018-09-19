#include"stack.h"
Node Push (Node Top,Elm_Type x)
{
    Node L = (Node) malloc (sizeof(stack));
    if(L == NULL)
    {
	puts("内存不足!");
	exit(1);
    }
    L -> Elm = x;
    L -> Next =  Top;
    return L;

}
Node Pop (Node Top)
{
    if(IsEmpty(Top))
    {
	puts("空栈!");
	return Top;
    }
    Node T;
    T = Top;
    Top = Top -> Next;
    free (T);
    return Top;
    
}
Elm_Type Stack_Top (Node Top)
{
    if(IsEmpty(Top))
    {
	puts("空栈!");
	return 0;
    }
    return Top -> Elm;
}
int IsEmpty (Node Top)
{
    return Top == NULL;
}
Node Init_stack (Node Top)
{
    int num,i;
    Node L;
    puts("输入你要建立的结点数:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
	L = (Node) malloc(sizeof(stack));
	if(L == NULL)
	{
	    puts("内存不足!");
	    return NULL;
	}
	puts("请输入数据:");
	scanf("%d",&L -> Elm);
	L -> Next = Top;
	Top = L;
    }
    return Top;
}




