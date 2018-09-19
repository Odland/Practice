#include "queue.h"
int main(void)
{
    Queue Q = Init_Queue();
    puts("开始入队,请输入数据:");
    ElementType num;
    while(scanf("%d",&num))
    {
	Enqueue(num,Q);
	puts("请输入数据:");
	if(getchar() != '\n')
	    continue;
    }
    printf("队顶元素是:%d\n",GetHead_Queue(Q));
    printf("长度为:%d\n",QueueLength(Q));  
    puts("依次出队:");
    while(!IsEmpty(Q))
	printf("%d\t",Dequeue(Q));
    putchar('\n');
    //printf("长度为:%d\n",QueueLength(Q));  
    return 0;
}
