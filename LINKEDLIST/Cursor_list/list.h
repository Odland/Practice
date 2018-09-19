#ifndef _CURSOR_LIST_
#define _CURSOR_LIST_
#define MaxSpace 30
#include <stdio.h>

typedef int Position;
typedef int ElementType;
typedef int Node;
typedef struct LIST{
    ElementType Element;
    Position Next;
}list;
list CursorSpace[MaxSpace];
void InitializeCursorSpace(void);
Position CursorAlloc(void);
void CursorFree(Position);
Position Find_list(const Node,ElementType);
Node FindPrevious_list(const Node,ElementType);
int Islast(Position);
int Isempty(Node);
void Ins_list(Node,ElementType);
void Del_list(Position);
void Traverse(Node);
void Clean_list(const Node);
#endif
