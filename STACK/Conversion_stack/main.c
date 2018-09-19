#include "conversion.h"
int main (void)
{
    int num,con;
    Stack S = Crea_stack();
    puts("请你输入一个十进制数数:");
    scanf("%d",&num);
    puts("请你输入基数:");
    scanf("%d",&con);
    ElementType N = Conver_stack(num,con);
    while(num >= con)
    {
	Push_stack(S,N);
	num /= con;
	N = Conver_stack(num,con);
	
    }
    Push_stack(S,N);
    while(S -> Top != -1)
    {
	printf("%d ",PopAndGetTop(S));
    }
    putchar('\n');
    return 0;
}
