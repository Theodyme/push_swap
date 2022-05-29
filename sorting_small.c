#include "push_swap.h"

void    sort_two(s_list **stack)
{
    if ((*stack)->content > (*stack)->next->content)
    {
        (*stack) = (*stack)->next;
        ft_printf("sa\n");
    }
}

void    sort_three(s_list  **stack)
{
    int fst;
    int scd;
    int trd;

    fst = (*stack)->content;
    scd = (*stack)->next->content;
    trd = (*stack)->prev->content;
    if (fst < scd && fst < trd && trd > scd)
        return ;
    if (fst < scd && fst < trd)
    {
        i_swap(stack, 'a');
        i_rotate(stack, 'a');
    }
    if (trd == get_min(stack))
    {
        if (fst > scd)
            i_swap(stack, 'a');
        i_reverser(stack, 'a');
    }
    if (scd < fst && scd < trd)
    {
        if (fst < trd)
            i_swap(stack, 'a');
        else
            i_rotate(stack, 'a');
    }
    return ;
}

void     sort_five(s_list  **a, s_list **b)
{
    int i;

    i = 2;
    while (i-- != 0)
    {
        sort_index(a);
        rot_to_i(a, 'a', rot_cost(a, 1));
        i_push(a, b, 'b');
    }
    sort_three(a);
    i = 2;
    while (i-- != 0)
    {
        i_push(b, a, 'a');
    }
    return ;
}
