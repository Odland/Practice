#include "conversio.h"
int main (void)
{
    char ch[20];
    puts("请你输入数学表达式:");
    fgets(ch,20,stdin);
    Stack S = Crea_stack(void);
    int len = strlen(ch);
    int i;
    char ch1[10];
    int j = 0;
    for(i=0;i<len;i++)
    {
	if(ch[i] == '+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||'('||ch[i]==')')
	{
	    if()
	    S->cha[++Top];
    
