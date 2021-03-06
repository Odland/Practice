#include"Tree.h"
int main(void)
{

    //建立一棵树
    Node Root = PreOrder_Crea_Tree();
    Stack S = Init_stack();
    //先序递归遍历
    puts("先序递归遍历:");
    PreOrder_Traversal(Root);
    //非递归先序遍历
    NR_PreOrder_Traversal(Root,S);
    //中序遍历
    printf("\n中序递归遍历:\n");
    InOrder_Traversal(Root);
    //初始化一个栈
    //Stack S = Init_stack();
    //非递归中序遍历
    NR_InOrder_Traversal(Root,S);
    //递归后序遍历
    puts("递归后序遍历:");
    PostOrder_Traversal(Root);
    //非递归后序遍历
    NR_PostOrder_Traversal(Root,S);
    //清除节点
    free_Postorder_BiT(Root);
    return 0;
}


