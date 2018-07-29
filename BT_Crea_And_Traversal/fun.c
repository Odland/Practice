#include "Tree.h"

//按照先根遍历的方式建立一棵二叉树
Node PreOrder_Crea_Tree(void)
{
    Node Root;
    ElementType temp;
    printf("请输入一个元素:\n");
    if(scanf("%d",&temp))
    {
        //清除缓冲区换行
        while(getchar() != '\n')
            continue;
        Root = (Node) malloc (sizeof(BT));
        if(Root == NULL)
        {
            printf("内存分配失败!\n");
            exit(1);
        }
        Root -> Element = temp;
        printf("这是一个左子树,");
        Root -> L = PreOrder_Crea_Tree();
        printf("这是一个右子树,");
        Root -> R = PreOrder_Crea_Tree();
    }
    else
    {
        while (getchar() != '\n')
            continue;
        Root = NULL;
    }
    //最终返回根Root
    return Root;
}
//先根遍历
void PreOrder_Traversal(Node Root)
{
    //这是一个先序遍历
    if (Root)
    {
        printf("%d\t",Root -> Element);
        PreOrder_Traversal (Root -> L);
        PreOrder_Traversal (Root -> R);
    }
}
//中根遍历
void InOrder_Traversal(Node Root)
{
    //这是一个中序遍历
    if(Root)
    {
        InOrder_Traversal(Root -> L);
        printf("%d\t",Root -> Element);
        InOrder_Traversal(Root -> R);
    }
}
//后根遍历
void PostOrder_Traversal(Node Root)
{
    //这是一个后序遍历
    if(Root)
    {
        PostOrder_Traversal(Root -> L);
        PostOrder_Traversal(Root -> R);
        printf("%d\t",Root -> Element);
    }
}
//利用后续遍历清除树
void free_Postorder_BiT(Node Root)
{
    if(Root)
    {
        free_Postorder_BiT(Root -> L);
        free_Postorder_BiT(Root -> R);
        free(Root);
    }
}
//非递归遍历
//建立堆栈


//判断是否为空
int IsEmpty(Stack S)
{
    return S -> Top == -1;
}
//判断栈是否满了没
int IsFull(Stack S)
{
    return S -> Top == Max_stack - 1;
}

//把树的节点元素值压进栈暂时保存
void Push_stack(Stack S,Node Root)
{
    if(IsFull(S))
    {
        puts("堆栈已满!");
        exit(1);
    }
    S -> Element[++S->Top] = Root; 
}

//把树的节点的值弹出来打印
Node Pop_stack(Stack S)
{
    if(IsEmpty(S))
    {
        puts("堆栈已空!");
        exit(1);
    }
    return S -> Element[S->Top--];
}

//初始化一个栈

Stack Init_stack(void)
{
    Stack S = (Stack) malloc (sizeof(struct stack));
    if(S == NULL)
    {
        puts("内存分配失败!");
        exit(1);
    }
    S -> Element = (struct TreeNode**) malloc(sizeof (Node) * Max_stack);
    if(S -> Element == NULL)
    {
        puts("内存分配失败!");
        exit(1);
    }
    S -> Top = -1;
    return S;
}   

//释放栈空间

void free_stack(Stack S)
{
    free(S -> Element);
    free(S);
}

//非递归遍历 中序遍历

void NR_InOrder_Traversal(Node Root,Stack S)
{
    printf("\n非递归中序遍历:\n");
    Node T = Root;
    while(T || !IsEmpty(S))
    {                                                                    
        while(T)
        {
            Push_stack(S,T);
            T = T -> L;
        }
        if(!IsEmpty(S))
        {
           Node P = Pop_stack(S);
           printf("%d\t",P -> Element);
           T = P -> R;
        }
    }
    putchar('\n');
}
//非递归前序遍历
void NR_PreOrder_Traversal(Node Root,Stack S)
{
      Node T = Root;
      putchar('\n');
      puts("非递归的前序遍历:");
      while(T || !IsEmpty(S))
      {
        while(T)
        {
            printf("%d\t",T -> Element);
            Push_stack(S,T);
            T = T -> L;
        }
        if(!IsEmpty(S))
        {
            T = Pop_stack(S);
            T = T -> R;
        }
      }
      putchar('\n');
}
//非递归后序遍历
void NR_PostOrder_Traversal(Node Root,Stack S)
{
    Node T = Root;
    while(T || !IsEmpty(S))
    {
        while(T)
        {
            Push_stack(S,T);
            T = T -> L;
        }
        if(!IsEmpty(S))
        {
            T = Pop_stack(S);
            if(T -> R == NULL)
            {
                printf("%d\t",T -> Element);
                T = Pop_stack(S);
                Push_stack(S,T);
               T = T -> R;
            }
            else
            {
                Push_stack(S,T);
                T = T -> R;
            }
        }
    }
}
