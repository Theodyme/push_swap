#include "push_swap.h"

void    quicksort(s_list **a, s_list **b)
{
    struct s_list   *tmp;
    int             cost;
    int             med;
    
    while (get_size(a) != 2)
    {
        sort_index(a);
        tmp = (*a);
        med = get_med(a);
        while (tmp->next != (*a))
        {
            if (get_size(a) == 3)
            {
                while (tmp->content != get_min(a))
                    tmp = tmp->next;
            }
            if ((tmp->index <= med) || (get_size(a) == 3))
            {
                // ft_printf("looking for the cost of rotating to %d.\n", tmp->content);
                cost = rot_cost(a, tmp->index);
                rot_to_i(a, 'a', cost);
                // ft_printf("pushing %d to stack b.\n", (*a)->content);
                i_push(a, b, 'b');
                // stackprinter(a, 'a');
                // indexprinter(a, 'a');
            }
            tmp = tmp->next;
        }
        // ft_printf("\n\nmoving to renewed a stack. ");
        // stackprinter(a, 'a');
    }
    stackprinter(a, 'a');
    stackprinter(b, 'b');
    return ;

}

void    rot_to_i(s_list **stack, char flag, int cost)
{
    if (cost == 0)
        return;
    if (cost < 0)
    {
        while (cost != 0)
        {
            i_rotate(stack, flag);
            // stackprinter(stack, 'a');
            cost++;
        }
    }
    else
    {
        while (cost != 0)
        {
            i_reverser(stack, flag);
            // stackprinter(stack, 'a');
            cost--;
        }
    }
    return ;
}

int    rot_cost(s_list **stack, int index)
{
    int up;
    int down;
    struct s_list *tmp;

    up = 1;
    down = 0;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        if(tmp->index == index)
            break ;
        tmp = tmp->next;
        down++;
    }
    tmp = (*stack)->prev;
    while (tmp->prev != (*stack))
    {
        if(tmp->index == index)
            break ;
        tmp = tmp->prev;
        up++;
    }
    // ft_printf("down = %d, up = %d.\n", down, up);
    if (down < up)
        return (down * (-1));
    else
        return (up);
}
