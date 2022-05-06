#include "push_swap.h"

int     i_swap(s_list **stack, char flag)
{
    s_list  *head;
    s_list  *top;

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