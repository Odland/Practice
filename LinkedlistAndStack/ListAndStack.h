#ifndef LIST_STACK_
#define LIST_STACK_
#include "stdio.h"
#include "stdlib.h"

#define Maxsize 100
typedef int ElementType;
//struct LIST;
typedef struct LIST *List;
struct LIST{
    ElementType List_Element;
    List Next;
};

struct STACK{
    ElementType *Stack_Element;
    int Top;
};
typedef struct STACK *Stack;

Stack Init_Stack (void);
List Init_List(void);
void Crea_List(List,ElementType);
void PrintList(List);
void Push_Stack(Stack,ElementType );
ElementType Pop_Stack(Stack);
void Print_Node(List,Stack);
void Pop_List(List,Stack);
#endif
