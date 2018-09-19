#include"ArrayQueue.h"
Queue Init(void)
{
    Queue Q = (Queue)malloc(sizeof(struct ArrayQ));
    if(Q==NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Q -> Element = (ElementType*)malloc(sizeof(ElementType) * Maxsize);
    if(Q -> Element == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    Q -> front = 0;
    Q -> rear = 0;
    return Q;
}
int IsFull(Queue Q)
{
    return (Q -> rear + 1) % Maxsize == Q -> front;

}
int IsEmpty(Queue Q)
{
    return Q -> rear == Q -> front;
}
void EnQueue(Queue Q,ElementType x)
{
    if(IsFull(Q))
    {
	puts("队列已满!");
	return;
    }
    Q -> rear = (Q -> rear + 1) % Maxsize;
    Q -> Element[Q -> rear] = x;
}
ElementType DeQueue(Queue Q)
{
    if(IsEmpty(Q))
    {
	puts("队列已空!");
	return 666;
    }
    Q -> front = (Q -> front + 1 ) % Maxsize;
    return Q -> Element[Q -> front];

}
void DeskTop(Queue Q)
{
    char num;
    int x;
    while(1)
    {
	puts("A 入队\tB 出队\tC 退出");
	puts("\n");
	scanf("%c",&num);
	while(getchar() != '\n')
	    continue;
	switch (num)
	{
	    case 'A' :
		puts("请入数据:");
		scanf("%d",&x);
		while(getchar() != '\n')
		    continue;
		EnQueue(Q,x);
		break;
	    case 'B' :
		printf("\n%d\n",DeQueue(Q));
		break;
	    case 'C' :
		return;
	    default:
		break;
	}
    }
    

}
