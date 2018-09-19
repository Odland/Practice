#include"ArrayQueue.h"
int main(void)
{
    //ElementType n;
    Queue Q = Init();
    /*puts("现在开始入队,请输入数据:");
    scanf("%d",&n);
    EnQueue(Q,n);
    puts("开始出队:");
    printf("%d\t",DeQueue(Q));*/
    DeskTop(Q);
    free(Q -> Element);
    free(Q);
    return 0;
}
