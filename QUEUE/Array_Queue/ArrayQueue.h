#ifndef ARR_QUEUE_
#define ARR_QUEUE_

#include <stdio.h>
#include <stdlib.h>

#define Maxsize 6

typedef struct ArrayQ * Queue;
typedef int ElementType ;
struct ArrayQ{
    int front;
    int rear;
    ElementType * Element;
};


Queue Init(void);
int IsFull(Queue);
int IsEmpty(Queue);
void EnQueue(Queue,ElementType);
ElementType DeQueue(Queue);
void DeskTop(Queue);

#endif
