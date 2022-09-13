#include <stddef.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


listnode* reverse_linked_list(listnode* param_1)
{

    listnode* head = param_1;
    listnode* prev = NULL;
    listnode* next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}