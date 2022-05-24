#include "push_swap.h"

int     sort_two(s_list **stack)
{
    if ((*stack)->content > (*stack)->next->content)
    {
        (*stack) = (*stack)->next;
        ft_printf("sa\n");
    }
    return (1);
}

int     sort_three(s_list  **stack)
{
    (void)stack;
    return (1);
}

