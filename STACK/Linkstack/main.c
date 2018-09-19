#include "stack.h"
int main (void)
{
    Node Top = NULL;
    Top = Init_stack(Top);
    /*
    Elm_Type m = Stack_Top(Top);
    printf("栈顶为%d\n",m);
    Top =  Pop(Top);
    m = Stack_Top(Top);
    printf("第二个栈顶为%d\n",m);
    int d;
    puts("请输入你要插入的元素");
    scanf("%d",&d);
    Top = Push(Top,d);
    m = Stack_Top(Top) ;
    printf("插入后的栈顶%d\n",m);
    */
    puts("请输入你要插入的元素的个数:");
    int x;
    scanf("%d",&x);
    int y;
    int j;
    for(y=0;y<x;y++)
    {
	puts("请输入元素:");
	scanf("%d",&j);
	Top = Push(Top,j);
    }
    Elm_Type m;
    while(Top)
    {
	m = Stack_Top(Top);
	Top = Pop(Top);
	printf("%d\t",m);
    }
    putchar('\n');
    return 0;
}

