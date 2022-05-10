#include "push_swap.h"

void    stackprinter(s_list **stack, char flag)
{
    s_list  *tmp;

    if ((*stack) == NULL)
    {
        ft_printf("%c stack content : \n", flag);
        return ;
    }
    tmp = *stack;
    ft_printf("%c stack content : \n", flag);
    while (tmp->next != *stack)
    {
        ft_printf("%d\n", tmp->content);
        // ft_printf("(prev: %d), ", tmp->prev->content);
        tmp = tmp->next;
    }
    ft_printf("%d\n", tmp->content);
    // ft_printf("(prev: %d).\n", tmp->prev->content);
    return ;
}