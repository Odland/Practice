#include"list.h"
void InitializeCursorSpace(void)
{
    int i;
    for(i = 0;i < MaxSpace - 1;i++)
    {
	CursorSpace[i].Next = i + 1;
    }
    CursorSpace[MaxSpace-1].Next = 0; 
}

Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}
void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}
Position Find_list(const Node Head,ElementType x)
{
    Node P = CursorSpace[Head].Next;
    while(P && CursorSpace[P].Element != x )
    {
	P = CursorSpace[P].Next;
    
    }
    return P;
}
Node FindPrevious_list(Node Head,ElementType x)
{
    Node P = Head;
    while(CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != x)
    {
	P = CursorSpace[P].Next;
    }
    return P;
}
int Islast(Position P)
{
    return CursorSpace[P].Next == 0;
}
int Isempty(Node Head)
{
    return CursorSpace[Head].Next == 0;
}
void Del_list(Position P)
{
    Position L = CursorSpace[P].Next;
    CursorSpace[P].Next = CursorSpace[L].Next;
    CursorFree(L);

}
void Ins_list(Node P,ElementType x)
{

    Node L = CursorAlloc();
    if (L == 0)
    {
	puts("内存分配失败!");
	return;
    }
    CursorSpace[L].Element = x;
    CursorSpace[L].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = L;
}
void Traverse (const Node Head)
{
    Node L = CursorSpace[Head].Next;
    if(Isempty(Head))
    {
	puts("空表!");
	return;
    }
    while(L)
    {
	printf("%d\t",CursorSpace[L].Element);
	L = CursorSpace[L].Next;
    }
    putchar('\n');


}
void Clean_list(const Node Head)
{
    Node T;
    while(CursorSpace[Head].Next)
    {
	T = CursorSpace[Head].Next;
	CursorSpace[Head].Next = CursorSpace[CursorSpace[Head].Next].Next;
	CursorFree(T);

    }
    CursorFree(Head);
    puts("释放成功!");
}
