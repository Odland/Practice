#include "ListAndStack.h"
Stack Init_Stack (void)
{
    Stack S = (Stack)malloc(sizeof(struct STACK));
    if(S == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    S -> Stack_Element = (ElementType*)malloc(sizeof(ElementType)*Maxsize);
    if(S -> Stack_Element == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    S -> Top = -1;
    return S;
}
List Init_List(void)
{
    List Head = (List)malloc(sizeof(struct LIST));
    if(Head == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Head -> Next = NULL;
    return Head;

}
void Crea_List(List Head,ElementType x)
{
    List Node = (List)malloc(sizeof(struct LIST));
    if(Node == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Node -> List_Element = x;
    Node -> Next = Head -> Next;
    Head -> Next = Node;


}
void PrintList(List Head)
{
    List Temp = Head;
    while(Temp -> Next != NULL)
    {
	printf("%d\t",Temp -> Next -> List_Element);
	Temp = Temp -> Next;
    }
    putchar('\n');
}
void Push_Stack(Stack S,ElementType x)
{
    if(S -> Top == Maxsize - 1)
    {
	puts("栈满!");
	exit(1);
    }
    S -> Stack_Element[++S -> Top] = x;


}
ElementType Pop_Stack(Stack S)
{
    if(S -> Top == -1)
    {
	puts("栈空!");
	exit(1);
    }
    return S -> Stack_Element[S -> Top--];
}
void Print_Node(List Head,Stack S)
{
    List T = Head;
    while(T -> Next != NULL)
    {
	Push_Stack(S,T -> Next -> List_Element);
	T = T -> Next;

    }

}
void Pop_List(List Head,Stack S)
{
    ElementType y;
    List H = Head;
    while(S -> Top != -1)
    {
		y = Pop_Stack(S);
		H -> Next -> List_Element = y;
		H = H -> Next;
    }

}

