#ifndef CIRCULAR_LINKED
#define CIRCULAR_LINKED
#include <stdio.h>
#include <stdlib.h>
struct NODE;
typedef struct NODE * Node;
typedef struct NODE list;
struct NODE{
    int num;
    Node Next;
};
void Isempty(Node);
void print_list(Node);
void Crea_list(Node);
void Ins_list(Node);
Node Posi_Find_list(Node);
Node Elem_Find_list(Node);
void Del_list(Node);
#endif
