#ifndef Tree_Linked_
#define Tree_Linked_

#include <stdio.h>
#include <stdlib.h>

#define Max_stack 30

//树的结构指针
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

//堆栈结构

typedef struct stack *Stack; 
struct stack{
    Node *Element;
    int Top;
};
//先序的方式建立一颗二叉树
Node PreOrder_Crea_Tree(void);
//先序遍历
void PreOrder_Traversal (Node);
//中序遍历
void InOrder_Traversal(Node);
//后序遍历
void PostOrder_Traversal(Node);
//清除树
void free_Postorder_BiT(Node);


//非递归遍历
int IsEmpty(Stack);//判断堆栈是否为空
int IsFull(Stack);//判断堆栈是否满了
void Push_stack(Stack,Node);//进栈
Node Pop_stack(Stack);//出栈
Stack Init_stack(void);//初始化栈
void free_stack(Stack);//清除栈空间
//非递归中序遍历
void NR_InOrder_Traversal(Node,Stack);
//非递归前序遍历
void NR_PreOrder_Traversal(Node,Stack);
//非递归后序遍历
void NR_PostOrder_Traversal(Node,Stack);



#endif
