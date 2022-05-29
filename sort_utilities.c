#include "push_swap.h"

int     get_max(s_list **stack)
{
    int max;
    struct s_list   *tmp;

    max = (*stack)->content;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        if (max < tmp->content)
            max = tmp->content;
        tmp = tmp->next;
    }
    if (max < tmp->content)
        max = tmp->content;
    // ft_printf("the max integer of the stack is %d.\n", max);
    return (max);
}

int     get_min(s_list **stack)
{
    int min;
    struct s_list   *tmp;

    min = (*stack)->content;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        if (min > tmp->content)
            min = tmp->content;
        tmp = tmp->next;
    }
    if (min > tmp->content)
        min = tmp->content;
    return (min);
}

int     get_size(s_list **stack)
{
    int size;
    struct s_list   *tmp;

    size = 0;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        size++;
        tmp = tmp->next;
    }
    size++;
    // ft_printf("the size of the stack is %d.\n", size);
    return (size);
}

int     get_med(s_list **stack)
{
    int med;

    med = (get_size(stack) / 2);
    // ft_printf("the median is %d.\n", med);
    if (((med % 2) != 0) && med != 1)
        med += 1;
    // ft_printf("the median is %d.\n", med);
    return (med);
}

