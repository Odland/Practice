#include"list.h"
int main (void)
{
    InitializeCursorSpace();
    const Node Head = CursorAlloc();
    if(Head == 0)
    {
	puts("没有多余的存储!");
	return 0;
    }
    CursorSpace[Head].Next = 0;
    CursorSpace[Head].Element = 0;
    puts("输入数量");
    int num;
    scanf("%d",&num);
    int i;
    Node L;
    for(i = 0;i < num;i++)
    {
	L = CursorAlloc();
	if(L == 0)
	{
	    puts("没有多余的存储空间!");
	    return 0;
	}
	puts("请输入数据:");
	scanf("%d",&CursorSpace[L].Element);
	CursorSpace[L].Next = CursorSpace[Head].Next;
	CursorSpace[Head].Next = L;

    }
    Traverse(Head);
    puts("请输入你要在哪个元素插入:");
    int ins;
    scanf("%d",&ins);
    Node N = Find_list(Head,ins);
    puts("请输入你要插入的元素:");
    int inss;
    scanf("%d",&inss);
    Ins_list(N,inss);
    Traverse(Head);
    puts("请输入你要删除的元素");
    int DEL;
    scanf("%d",&DEL);
    Node D = FindPrevious_list(Head,DEL);
    Del_list(D);
    Traverse(Head);
    Clean_list(Head);
    //Traverse(Head);
    return 0;
}
