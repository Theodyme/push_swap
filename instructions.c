#include "push_swap.h"

void    i_swap(s_list **stack, char flag)
{
    int tmp;

    tmp = (*stack)-> content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
    if (flag)
        ft_printf("s%c\n", flag);
    return ;
}

void    i_push(s_list **from, s_list **to, char flag)
{
    struct s_list  *tofree;

    tofree = (*from);
    addfront(to, (*from)->content);
    if (get_size(from) == 1)
    {
        ft_printf("p%c\n", flag);
        free(tofree);
        (*from) = NULL;
        return ;
    }
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
    if (flag)
        ft_printf("r%c\n", flag);
    return ;
}

void    i_reverser(s_list **stack, char flag)
{
    (*stack) = (*stack)->prev;
    if (flag)
        ft_printf("rr%c\n", flag);
    return ;
}

void    i_double(s_list **a, s_list **b, char flag)
{
    if (flag == 's')
    {
        i_swap(a, '\0');
        i_swap(b, '\0');
        ft_printf("ss\n");
    }
    if (flag == 'r')
    {
        i_rotate(a, '\0');
        i_rotate(b, '\0');
        ft_printf("rr\n");
    }
    if (flag == 'v')
    {
        i_reverser(a, '\0');
        i_reverser(b, '\0');
        ft_printf("rrr\n");
    }
    return ;
}