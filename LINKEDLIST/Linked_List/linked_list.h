#ifndef Linked_List_h
#define Linked_list_h
typedef struct Node{
    int data;
    struct Node *Next;
}*Position,*List;
//PtrToNode  List;	//链表
//PtrToNode Position;//结构指针，指出位置

typedef int  Ele_Type;//类型

//List MakeEmpty (List L);
//int IsEmpty (List L);
//int IsLast (Position P,List L);
//Position Find (ElementType X,List L);
//void Insert(ElementType X,List L,Position P);
//void DeleteList(List L);
//Position First(List L);
//Position Header(List L);
//Position Advance (Position P);
//ElementType Retrieve(Position P);
List Create_list(List);//创建一个链表
void Print_list (List);//输出链表的数据
int IsLast (List);//判断是否到达最后一个节点
void Find(Ele_Type,List);//按值查找
void Ins_list (List,Ele_Type,int);//插入数据
int Isempty(List);//是否是空表
void Del_list(List,Ele_Type);//删除数据
void Clea_list(List);//清除链表
void display(List);//菜单
int get_inter(void);//switch语句里获取整数
Position find_previous(List,Ele_Type);//获得目标元素的前一个元

#endif
