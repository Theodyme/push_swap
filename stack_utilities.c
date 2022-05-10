#include "push_swap.h"

int    dupchecker(s_list **stack)
{
    s_list  *tmp;
    s_list  *node;
    int checker;

    node = *stack;
    while (node->next != *stack)
    {
        checker = node->content;
        tmp = node->next;
        while (tmp->next != (*stack)->next)
        {
            // ft_printf("I'm looking for %d. The current node contains %d.\n", checker, tmp->content);
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
        *stack = node;
        return ;
    }
    last = (*stack)->prev;
    node->next = *stack;
    last->next = node;
    node->prev = last;
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

struct s_list   **stackbuilder(char **av, s_list **stack)
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
    return (stack);
}