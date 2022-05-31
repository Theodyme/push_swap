#include "push_swap.h"

struct s_list     *find_nearest(s_list **a, int i)
{
    struct s_list   *tmp;
    struct s_list   *sup;
    int             lowest;
    int             current;

    tmp = (*a);
    while (tmp->next != (*a) && tmp->content != get_min(a))
        tmp = tmp->next;
    lowest = 0;
    sup = tmp;
    tmp = (*a);
    while (tmp->next != (*a))
    {
        if ((tmp->content > i))
        {
            current = (tmp->content) - i;
            if (((lowest > current) && (lowest != 0)) || lowest == 0)
            {
                lowest = current;
                sup = tmp;
            }
        }
        tmp = tmp->next;
    }
    if ((tmp->content > i))
    {
        current = (tmp->content) - i;
        if (((lowest > current) && (lowest != 0)) || lowest == 0)
        {
            lowest = current;
            sup = tmp;
        }
    }
    return (sup);
}

void    fill_costs(s_list **a, s_list **b)
{
    struct s_list   *tmp;

    if ((*b) == NULL || get_size(b) == 0)
        return ;
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

    if (!(*stack))
        return (0);
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
    if (down < up)
        return (down * (-1));
    else
        return (up);
}

void     is_double(s_list **a, s_list **b, s_list **nearest, s_list **target)
{
    if ((*a) != (*nearest) && (*b) != (*target) && ((*nearest)->cost * (*target)->cost) > 0)
    {
        while (((*target)->cost < 0) && ((*nearest)->cost < 0))
        {
            i_double(a, b, 'r');
            (*target)->cost++;
            (*nearest)->cost++;
        }
        while (((*target)->cost > 0) && ((*nearest)->cost > 0))
        {
            i_double(a, b, 'v');
            (*target)->cost--;
            (*nearest)->cost--;
        }
    }
    return ;
}

void    executing_costs(s_list **a, s_list **b, s_list **nearest, s_list **target)
{
    is_double(a, b, nearest, target);
    if ((*a) != (*nearest) || (*b) != (*target))
    { 
        while ((*a) != (*nearest))
        {
            while ((*nearest)->cost < 0)
            {   
                i_rotate(a, 'a');
                (*nearest)->cost++;
            }
            while ((*nearest)->cost != 0)
            {
                i_reverser(a, 'a');
                (*nearest)->cost--;
            }
        }
        while ((*b) != (*target))
        {
            while ((*target)->cost < 0)
            {   
                i_rotate(b, 'b');
                (*target)->cost++;
            }
            while ((*target)->cost != 0)
            {
                i_reverser(b, 'b');
                (*target)->cost--;
            }
        }
    }
    return ;
}

void    insertsort(s_list **a, s_list **b)
{
    int             lowest;
    struct s_list   *target;
    struct s_list   *nearest;
    struct s_list   *btmp;

    btmp = (*b);
    fill_costs(a, b);
    target = btmp;
    nearest = find_nearest(a, btmp->content);
    lowest = ft_abs(btmp->cost) + ft_abs(nearest->cost);
    btmp = btmp->next;
    while (btmp != (*b))
    {
        if (lowest > (ft_abs(btmp->cost) + ft_abs((find_nearest(a, btmp->content))->cost)))
        {
            lowest = ft_abs((find_nearest(a, btmp->content))->cost);
            nearest = find_nearest(a, btmp->content);
            target = btmp;
        }
        btmp = btmp->next;
    }
    if (lowest > ft_abs(btmp->cost) + ft_abs((find_nearest(a, btmp->content))->cost))
    {
        lowest = ft_abs((find_nearest(a, btmp->content))->cost);
        nearest = find_nearest(a, btmp->content);
        target = btmp;
    }
    executing_costs(a, b, &nearest, &target);
    i_push(b, a, 'a');
    return ;
}