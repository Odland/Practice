#include"conversion.h"
Stack Crea_stack(void)
{
    Stack S = (Stack) malloc(sizeof(struct STACK));
    if(S == NULL)
    {
	puts("分配内存失败!");
	exit(1);
    }
    S -> cha = (char*) malloc(sizeof(char)*Maxsize);
    if(S -> cha == NULL)
    {
	puts("内存分配失败!");
	exit(1);
    }
    S -> Top = -1;
    return S;
}

