#include "queue.h"
Queue Init_Queue(void)
{
    Queue Q = (Queue)malloc(sizeof(struct LinkedQueue));
    if(Q == NULL)
    {
	puts("分配内存失败!");
	exit(1);
    }
    Qnode N = (Qnode)malloc(sizeof(struct node));
    if(N == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    N -> Next = NULL;
    Q -> front = Q -> rear = N;
    return Q;
}

ElementType GetHead_Queue(Queue Q)
{
    if(IsEmpty(Q))
    {
	puts("空队!");
	exit(1);
    }
    return Q -> front -> Next -> Element;
}

int IsEmpty(Queue Q)
{
    return Q -> front == Q -> rear;
}
ElementType Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
	puts("空队!");
	exit(1);
    }
    Qnode Temp = Q -> front -> Next;
    ElementType x = Q -> front -> Next -> Element;
    //Q -> front -> Next = Q -> front -> Next -> Next;
    if(Q -> front -> Next -> Next == NULL)
	Q -> rear = Q -> front;
    else
    Q -> front -> Next = Q -> front -> Next -> Next;
    free (Temp);
    return x;
    
}
void Enqueue(ElementType x,Queue Q)
{
    Qnode N = (Qnode)malloc(sizeof(struct node));
    if(N == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    N -> Element = x;
    N -> Next = NULL;
    Q -> rear -> Next = N;
    Q -> rear = N;
}

int QueueLength(Queue Q)
{
    int i=0;
    Qnode T = Q -> front -> Next;
    while(T != NULL)
    {
	i++;
	T  = T -> Next;
	
    }
    return i;

}
