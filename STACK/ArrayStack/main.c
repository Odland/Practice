#include "stack.h"
int main (void)
{
    stack S = Crea_stack();
    puts("进栈:");
    puts("请输入个数:");
    int num;
    scanf("%d",&num);
    int i;
    int Elm;
    for(i=0;i<num;i++)
    {
	puts("请输入数据:");
	scanf("%d",&Elm);
	Push_stack(S,Elm);
    }
    puts("现在开始输出栈:");
    while(S -> Top != EmptyStack)
    {
	printf("%d\t",Pop_GetTop(S));
    }
    putchar('\n');
    Dispose_stack(S);
    puts("销毁成功!");
    return 0;
}
