#include "push_swap.h"

void    i_swap(s_list **stack, char flag)
{
    int tmp;

    tmp = (*stack)-> content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
    ft_printf("s%c\n", flag);
    return ;
}

void    i_push(s_list **from, s_list **to, char flag)
{
    struct s_list  *tofree;

    tofree = (*from);
    addfront(to, (*from)->content);
    (*from)->prev->next = (*from)->next;
    (*from)->next->prev = (*from)->prev;
    (*from) = (*from)->next;
    free(tofree);
    ft_printf("p%c\n", flag);
    return ;
}

void    i_rotate(s_list **stack, char flag)
{
    (*stack) = (*stack)->next;
    ft_printf("r%c\n", flag);
    return ;
}

void    i_reverser(s_list **stack, char flag)
{
    (*stack) = (*stack)->prev;
    ft_printf("rr%c\n", flag);
    return ;
}

void    i_double(s_list **a, s_list **b, char flag)
{
    if (flag == 's')
    {
        i_swap(a, 'a');
        i_swap(b, 'b');
    }
    if (flag == 'r')
    {
        i_rotate(a, 'a');
        i_rotate(b, 'b');
    }
    if (flag == 'v')
    {
        i_reverser(a, 'a');
        i_reverser(b, 'b');
    }
    return ;
}