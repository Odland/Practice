#ifndef A_D_Stack_
#define A_D_Stack_
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int ElementType;
struct stack{
    int Top;
    int Tail;
    ElementType *num;
};
typedef struct stack* Stack;
Stack Crea_stack(void);
void Push_stack(Stack,ElementType,int);
int IsFull(int);
int IsEmpty_Top(int);
int IsEmpty_Tail(int);
ElementType PopAndGetelement(Stack,int);
#endif

