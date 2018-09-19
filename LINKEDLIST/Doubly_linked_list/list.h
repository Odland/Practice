#ifndef LINKED_LIST

#define LINKED_LIST
#include <stdio.h>
#include <stdlib.h>
struct LIST;
typedef struct LIST *Node;
typedef struct LIST list;
struct LIST{
    int num;
    Node Next;
    Node Prec;
};

Node crea_Doubly_linked(Node);
void N_print_list(Node);
void P_print_list(Node);
int count_list(Node);
void ins_list(Node,Node);
Node Find_list(Node);
void Del_list(Node,Node);
void clean_list(Node,Node);
#endif
