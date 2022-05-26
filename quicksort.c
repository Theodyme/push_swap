#include "push_swap.h"

void    quicksort(s_list **a, s_list **b)
{
    struct s_list   *tmp;
    int             cost;
    int             med;
    int             i;

    while (get_size(a) != 2)
    {
        i = 1;
        tmp = (*a);
        med = get_med(a);
        sort_index(a);
        while (i <= med)
        {
            tmp = (*a);
            indexprinter(a, 'a');
            ft_printf("looking for the index %d...\n", i);
            while (tmp->next != (*a))
            {
                ft_printf("current index is %d.\n", tmp->index);
                if (tmp->index == i)
                {
                    ft_printf("looking for the cost of rotating to %d.\n", tmp->content);
                    cost = rot_cost(a, tmp->index);
                    rot_to_i(a, 'a', cost);
                    ft_printf("pushing %d to stack b.\n", (*a)->content);
                    i_push(a, b, 'b');
                    stackprinter(a, 'a');
                    break ;
                }
                tmp = tmp->next;
            }
            i++;
        }
        // while (tmp->next != (*a))
        // {
        //     if (tmp->index <= med)
        //     {
        //         ft_printf("looking for the cost of rotating to %d.\n", tmp->content);
        //         cost = rot_cost(a, tmp->index);
        //         rot_to_i(a, 'a', cost);
        //         ft_printf("pushing %d to stack b.\n", (*a)->content);
        //         i_push(a, b, 'b');
        //         stackprinter(a, 'a');
        //         indexprinter(a, 'a');
        //     }
        //     tmp = tmp->next;
        // }
        ft_printf("\n\nmoving to renewed a stack. ");
        stackprinter(a, 'a');
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
            stackprinter(stack, 'a');
            cost++;
        }
    }
    else
    {
        while (cost != 0)
        {
            i_reverser(stack, flag);
            stackprinter(stack, 'a');
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
    ft_printf("down = %d, up = %d.\n", down, up);
    if (down < up)
        return (down * (-1));
    else
        return (up);
}