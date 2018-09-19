#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include<stdio.h>
#include<stdlib.h>
typedef struct node *Qnode;
typedef struct LinkedQueue *Queue;
typedef int ElementType;
struct node{
    ElementType Element;
    Qnode Next;
};
struct LinkedQueue{
    Qnode front;
    Qnode rear;
};


Queue Init_Queue(void);
ElementType GetHead_Queue(Queue Q);
int IsEmpty(Queue Q);
ElementType Dequeue(Queue Q);
void Enqueue(ElementType x,Queue Q);
int QueueLength(Queue Q);

#endif
