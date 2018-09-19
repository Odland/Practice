#include "conversion.h"
Stack Crea_stack(void)
{
    Stack S = (Stack)malloc(sizeof(struct Convesrsion));
    if(S == NULL)
    {
	puts("内存分配失败");
	return NULL;
    }
    S -> Arr = (ElementType*)malloc(sizeof(ElementType)*Maxsize);
    if(S->Arr == NULL)
    {
	puts("内存分配失败!");
	return NULL;
    }
    S -> Top = -1;
    return S;

}
int IsFull(int Top)
{
    return Top == Maxsize - 1;
}
int IsEmpty (int Top)
{
    return Top == -1;
}
void Push_stack(Stack S,ElementType x)
{
    if(IsFull(S -> Top ))
    {
	puts("栈已满");
	return;
    }
    S -> Top++;
    S -> Arr[S->Top] = x;

}
ElementType PopAndGetTop(Stack S)
{
    if(IsEmpty(S->Top))
    {
	puts("空栈!");
	return 9999;
    }
    
    return S->Arr[S->Top--];

}
ElementType Conver_stack(ElementType x,int con)
{
   return x % con;
}
