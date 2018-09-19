#ifndef _CONVERSION_STACK_
#define _CONVERSION_STACK_
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100

struct Convesrsion;
typedef int ElementType;
typedef struct Convesrsion *Stack;
struct Convesrsion{
    int Top;
    ElementType *Arr;
};

Stack Crea_stack(void);
int IsFull(int);
int IsEmpty(int);
void Push_stack(Stack,ElementType);
ElementType PopAndGetTop(Stack);
ElementType Conver_stack(ElementType,int);

#endif
