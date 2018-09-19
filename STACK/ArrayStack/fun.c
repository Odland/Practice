#include "stack.h"
stack Crea_stack (void)
{
    stack S = (stack) malloc(sizeof(struct Stack));
    if(S == NULL)
    {
	puts("内存不足!");
	return NULL;
    }
    S -> Arr = (Elm_Type*) malloc(sizeof(Elm_Type)*MaxSize);
    if(S -> Arr == NULL)
    {
	puts("内存不足!");
	return NULL;
    }
    S -> Top = EmptyStack;
    return S;
}
int IsEmpty(int Top)
{
    return Top == EmptyStack;
}
int IsFull(int Top)
{
    return Top == MaxSize - 1;
}
void Push_stack(stack S,Elm_Type x)
{
    if(IsFull(S -> Top))
    {
	puts("空间已满!");
	exit(1);
    }
    S -> Top++;
    S -> Arr[S -> Top] = x;
}
Elm_Type Pop_GetTop(stack S)
{
    if(IsEmpty(S -> Top))
    {
	puts("栈已空");
	return 0;
    }
    //S -> Arr[S -> Top] = 0;
    Elm_Type T = S -> Arr[S -> Top]; 
    S -> Top--;
    return T;
}
void Dispose_stack (stack S)
{
    if(!S)
    {
	puts("结构指针为NULL!");
	return;
    }
    free(S -> Arr);
    free(S);
}

