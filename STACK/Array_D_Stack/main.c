#include"ArrayStack.h"
int  main(void)
{
    int i,j,k;
    Stack S = Crea_stack();
    puts("现在请你开始输入数据:");
    puts("你要在哪个栈建立数据输入1或2");
    scanf("%d",&i);
    puts("请输入数据:");
    scanf("%d",&j);
    Push_stack(S,j,i);
    puts("请你输入要出栈的编号:");
    scanf("%d",&k);
    printf("%d\n",PopAndGetelement(S,k));

    printf("%d\n",PopAndGetelement(S,k));
    return 0;
}
