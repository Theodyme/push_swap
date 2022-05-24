#include "push_swap.h"

void    set_index(s_list **stack)
{
    int i;
    struct s_list   *tmp;

    i = 1;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        tmp->index = i;
        i++;
        tmp = tmp->next;
    }
    tmp->index = i;
    return ;
}