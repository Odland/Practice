struct NODE;
typedef struct NODE * Node;
typedef struct NODE list;
struct NODE{
    int Coe;
    int Expo;
    Node Next;
};
void crea_list(Node);
void print_list (Node);
Node add_list(Node,Node);
Node Mult (Node,Node);
void clean_list(Node);
