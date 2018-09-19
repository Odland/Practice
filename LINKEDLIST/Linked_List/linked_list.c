#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
//#include <string.h>
int main (void)
{
    //设置头结点
    List header=(List) malloc(sizeof(struct Node));
    header->Next = NULL;

   // Create_list(header);
   display(header);
    
    return 0;
}
