#include <stddef.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


listnode* remove_duplicates_from_sorted_list(listnode* param_1)
{
    listnode* head = param_1;
    listnode* prev = NULL;
    listnode* curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            while (curr->next != NULL && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            if (prev != NULL)
            {
                prev->next = curr;
            }
            else
            {
                head = curr;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}