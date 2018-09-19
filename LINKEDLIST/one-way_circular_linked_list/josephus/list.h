#ifndef _JOSEPHUS_LIST
#define _JOSEPHUS_LIST
#include <stdio.h>
#include <stdlib.h>
struct NODE;
typedef struct NODE *Node;
typedef struct NODE list;
struct NODE{
    int num;
    Node Next;
};
void Crea_list(Node,int);
int * Josep_list(Node,int*,int,int);
Node Find_list(Node,int);
int Count_list(Node);
void print_list(int *,int);
#endif
