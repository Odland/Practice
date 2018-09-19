#include"ArrayStack.h"
Stack Crea_stack(void)
{
    Stack S = (Stack)malloc(sizeof(struct stack));
    if(S == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    S -> num = (ElementType*)malloc(sizeof(ElementType)*Maxsize);
    if(S -> num == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    S->Top = -1;
    S->Tail = Maxsize;
    return S;
}
void Push_stack(Stack S,ElementType x,int l)
{
    if(IsFull(S->Tail - S->Top))
    {
	puts("栈满!");
	exit(1);
    }
    if(l == 1)
    {
	S->num[++S->Top] = x;
    }
    else
	S->num[--S->Tail] = x;

}
int IsFull(int n)
{
    return n == 1;
}
int IsEmpty_Top(int Top)
{
    return Top == -1;
}
int IsEmpty_Tail(int Tail)
{
    return Tail == Maxsize;
}
ElementType PopAndGetelement(Stack S,int g)
{
    if(g == 1)
    {
	if(IsEmpty_Top(S->Top))
	{
	    puts("1空栈!");
	    exit(1);
	}
	return S->num[S->Top--];
    }
    else
    {
	if(IsEmpty_Tail(S->Tail))
	{
	    puts("2空栈!");
	    exit(1);
	}
	return S->num[S->Tail++];
    
    }
}


