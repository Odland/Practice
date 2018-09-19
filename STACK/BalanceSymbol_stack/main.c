#include <stdio.h>
#include <stdlib.h>

#define ElementType char
#define Maxsize 50
typedef struct Stack{
    ElementType *symbol;
    int Top;
}*stack;



stack Crea_stack(void);
void Push_stack(stack,ElementType);
void Pop_stack(stack);
ElementType GetTop(stack);
int IsEmpty(int);
int IsFull(int);
void menu(stack,ElementType);

int main (void)
{
    stack S = Crea_stack();
  
    puts("请你输入符号:");
    ElementType ch;
    while(scanf("%c",&ch) == 1)
    {
	menu(S,ch);
	while(getchar() != '\n')
	    continue;
	puts("请你输入符号:");
    }
    return 0;
}
stack Crea_stack(void)
{
    stack S = (stack)malloc(sizeof(struct Stack));
    if(S == NULL)
    {
	puts("内存分配失败!");
	return NULL;
    }
    S -> symbol = (ElementType*)malloc(sizeof(ElementType)*Maxsize);
    if(S -> symbol == NULL)
    {
	puts("内存分配失败!");
	return NULL;
    }
    S -> Top = -1;
    return S;
}
void Push_stack(stack S,ElementType x)
{
    if(IsFull(S -> Top))
    {
	puts("栈满!");
	return;
    }
    S -> symbol[++S->Top] = x;
}
void Pop_stack(stack S)
{
    S->Top--;
}
ElementType GetTop(stack S)
{
    if(IsEmpty(S -> Top))
    {
	puts("栈空,匹配失败!");
	exit(1);
    }
    return S -> symbol[S -> Top];
}

int IsFull(int Top)
{
    return Top == Maxsize - 1;
}
int IsEmpty(int Top)
{
    return Top == -1;
}
void menu (stack S,ElementType Element)
{
    //ElementType Temp;
    if(Element == '{' || Element == '(' || Element == '[')
    {
	Push_stack(S,Element);
    }
    else
    {
	switch (Element)
	{
	    case '}':
		if(GetTop(S) == '{')
		    Pop_stack(S);
		else
		{
		    puts("匹配错误!");
		    exit(1);
		}
		break;
	    case ')':
		if(GetTop(S) == '(')
		    Pop_stack(S);
		else
		{
		    puts("匹配错误!");
		    return;
		}
		break;
	    case ']':
		if(GetTop(S) == '[')
		    Pop_stack(S);
		else
		{
		    puts("匹配错误!");
		    return;
		}
		break;
	    default:
		puts("非法字符!");
		return;
	}
    }
}
