#include "push_swap.h"

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

int     main(int ac, char **av)
{
    static s_list   *a = NULL;
    int i;

    i = 1;
    while(i < ac)
    {
        ft_printf("av[i] = %d,\n", ft_atoi(av[i]));
        addback(&a, ft_atoi(av[i]));
        i++;
    }
    stackprinter(&a);
    return (0);
}