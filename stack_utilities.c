#include "push_swap.h"

int    checker(s_list **a, s_list **b)
{
    struct s_list  *tmp;

    if ((*b))
        return (0);
    if ((*a) && !(*a)->next)
    {
        ft_printf("OK");
        return (1);
    }
    tmp = (*a);
    while (tmp->next != *a)
    {
        if (tmp->content > tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    ft_printf("OK");
    return (1);
}

int    dupchecker(s_list **stack)
{
    struct s_list  *tmp;
    struct s_list  *node;
    int checker;

    node = *stack;
    while (node->next != *stack)
    {
        checker = node->content;
        tmp = node->next;
        while (tmp->next != (*stack)->next)
        {
            if (tmp->content == checker)
                return (1);
            tmp = tmp->next;
        }
        node = node->next;
    }
    return (0);
}

void  addback(s_list **stack, int nbr)
{
    struct s_list   *node;
    struct s_list   *last;

    node = malloc(sizeof(s_list));
    node->content = nbr;
    if(!*stack)
    {
        node->next = node;
        node->prev = node;
        node->index = 1;
        *stack = node;
        return ;
    }
    last = (*stack)->prev;
    node->next = *stack;
    last->next = node;
    node->prev = last;
    node->index = (node->prev->index + 1);
    (*stack)->prev = node;
    return ;
}

void  addfront(s_list **stack, int nbr)
{
    struct s_list   *node;
    struct s_list   *last;

    node = malloc(sizeof(s_list));
    node->content = nbr;
    if(!*stack)
    {
        node->next = node;
        node->prev = node;
        *stack = node;
        return ;
    }
    last = (*stack)->prev;
    node->prev = last;
    node->next = *stack;
    last->next = node;
    (*stack)->prev = node;
    *stack = node;
    return ;
}

void   stackbuilder(char **av, s_list **stack)
{
    int     i;
    int     j;
    int     k;

    j = 1;
    while(av[j])
    {
        i = 0;
        while(av[j][i])
        {
                k = 0;
                while(av[j][i] && (ft_isdigit(av[j][i + k]) == 1 || av[j][i + k] == '-'))
                {
                    k++;
                }
                if (k != 0)
                {
                    addback(stack, ft_atoi((&av[j][i])));
                    i += (k - 1);
                }
                i++;
        }
        j++;
    }
    return ;
}