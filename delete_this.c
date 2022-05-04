#include "push_swap.h"

void    stackprinter(s_list **stack)
{
    s_list  *tmp;

    tmp = *stack;
    ft_printf("stack content : ");
    while (tmp->next != *stack)
    {
        ft_printf("%d, ", tmp->content);
        tmp = tmp->next;
    }
    ft_printf("%d.\n", tmp->content);
    return ;
}