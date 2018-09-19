#ifndef _LINKSTACK_
#define _LINKSTACK_
#include <stdio.h>
#include <stdlib.h>

typedef int Elm_Type;
struct Stack;
typedef struct Stack *Node;
typedef struct Stack stack;
struct Stack{
    Elm_Type Elm;
    Node Next;
};
Node Push(Node,Elm_Type);
Node Pop(Node);
Elm_Type Stack_Top (Node);
int IsEmpty (Node);
Node Init_stack(Node);
#endif
