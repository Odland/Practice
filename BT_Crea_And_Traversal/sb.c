#include<stdio.h>
#include<stdlib.h>
#define  Max_stack 20
typedef struct TreeNode *Node;
//树的结构变量
typedef struct TreeNode BT;
//树的节点元素
typedef int ElementType;
//树结构
struct TreeNode{
    Node L;
    Node R;
    ElementType Element;
};
typedef struct stack *Stack; 
struct stack{
    Node *Element;
    int Top;
};
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
/*typedef struct TreeNode *Node;
//树的结构变量
typedef struct TreeNode BT;
//树的节点元素
typedef int ElementType;
//树结构
struct TreeNode{
    Node L;
    Node R;
    ElementType Element;
*/
int main(void)
{
    Init_stack();
    return 0;
}
