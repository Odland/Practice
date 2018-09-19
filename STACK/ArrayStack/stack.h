#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
#define EmptyStack -1

struct Stack;
typedef int Elm_Type;
typedef struct Stack *stack;
struct Stack{
    int Top;
    Elm_Type *Arr;
};

stack Crea_stack (void);
int IsEmpty (int);
int IsFull (int);
void Push_stack(stack,Elm_Type);
Elm_Type Pop_GetTop (stack);
void Dispose_stack(stack);
#endif
