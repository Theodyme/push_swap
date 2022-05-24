#include "push_swap.h"

int     i_swap(s_list **stack, char flag)
{
    struct s_list  *head;
    struct s_list  *top;

    head = (*stack);
    top = head->next;
    head->next = top->next;
    top->next = head;
    top->prev = (*stack)->prev;
    (*stack)->prev->next = top;
    head = head->next;
    head->prev = top;
    (*stack) = top;
    ft_printf("s%c\n", flag);
    return (1);
}

int     i_push(s_list **from, s_list **to, char flag)
{
    struct s_list  *tofree;

    tofree = (*from);
    addfront(to, (*from)->content);
    (*from)->prev->next = (*from)->next;
    (*from)->next->prev = (*from)->prev;
    (*from) = (*from)->next;
    free(tofree);
    ft_printf("p%c\n", flag);
    return (1);
}

int     i_rotate(s_list **stack, char flag)
{
    (*stack) = (*stack)->next;
    ft_printf("r%c\n", flag);
    return (1);
}

int     i_reverser(s_list **stack, char flag)
{
    (*stack) = (*stack)->prev;
    ft_printf("rr%c\n", flag);
    return (1);
}