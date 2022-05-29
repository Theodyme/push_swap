#include "push_swap.h"

int     node_cost(s_list **stack, int i)
{
    struct s_list   *tmp;
    int             cost;

    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        if (tmp->content == i)
        {
            cost = tmp->cost;
            break;
        }
        tmp = tmp->next;
    }
    return (cost);
}

int     find_nearest(s_list **a, int i)
{
    struct s_list   *tmp;
    int             dist;
    int             sup;

    tmp = (*a);
    dist = i - (tmp->content);
    sup = tmp->content;
    tmp = tmp->next;
    while (tmp->next != (*a))
    {
        if ((tmp->content > i) && (dist > (i - (tmp->content))))
        {
            dist = (i - (tmp->content));
            sup = tmp->content;
        }
        tmp = tmp->next;
    }
    return (sup);
}

void    fill_costs(s_list **a, s_list **b)
{
    struct s_list   *tmp;

    tmp = (*b);
    while (tmp->next != (*b))
    {
        tmp->cost = cost_to_top(b, tmp->content);
        tmp = tmp->next;
    }
    tmp->cost = cost_to_top(b, tmp->content);
    tmp = (*a);
    while (tmp->next != (*a))
    {
        tmp->cost = cost_to_top(a, tmp->content);
        tmp = tmp->next;
    }
    tmp->cost = cost_to_top(a, tmp->content);
    return ;
}

int    cost_to_top(s_list **stack, int i)
{
    int up;
    int down;
    struct s_list *tmp;

    up = 1;
    down = 0;
    tmp = (*stack);
    while (tmp->next != (*stack))
    {
        if(tmp->content == i)
            break ;
        tmp = tmp->next;
        down++;
    }
    tmp = (*stack)->prev;
    while (tmp->prev != (*stack))
    {
        if(tmp->content == i)
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

void    insertsort(s_list **a, s_list **b)
{
    int             lowest;
    int             target;
    int             nearest;
    struct s_list   *btmp;

    btmp = (*b);
    fill_costs(a, b);
    // costprinter(a, 'a');
    // costprinter(b, 'b');
    target = btmp->content;
    nearest = find_nearest(a, btmp->content);
    lowest = ft_abs(btmp->cost) + ft_abs(node_cost(a, nearest));
    while (btmp->next != (*b))
    {
        if (lowest > ft_abs(btmp->cost) + ft_abs(node_cost(a, find_nearest(a, btmp->content))))
        {
            lowest = ft_abs(node_cost(a, find_nearest(a, btmp->content)));
            nearest = find_nearest(a, btmp->content);
            target = btmp->content;
        }
        btmp = btmp->next;
    }
    if (lowest > ft_abs(btmp->cost) + ft_abs(node_cost(a, find_nearest(a, btmp->content))))
    {
        lowest = ft_abs(node_cost(a, find_nearest(a, btmp->content)));
        nearest = find_nearest(a, btmp->content);
        target = btmp->content;
    }
    rot_to_i(b, 'b', node_cost(b, target));
    rot_to_i(a, 'a', node_cost(a, nearest));
    i_push(b, a, 'a');
    stackprinter(a, 'a');
    stackprinter(b, 'b');
    return ;
}