#include "push_swap.h"

int    dupchecker(s_list **stack)
{
    s_list  *tmp;

    tmp = *stack;
    ft_printf("stack content : ");
    while (tmp->next != *stack)
    {
        ft_printf("%d, ", tmp->content);
        tmp = tmp->next;
    }
    ft_printf("%d.\n", tmp->content);
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
    node->next = *stack;
    node->prev = last;
    last->next = node;
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
                while(av[j][i] && ft_isdigit(av[j][i + k]) == 1)
                {
                    k++;
                }
                if (k != 0)
                {
//                    ft_printf("adding the number %d to the stack...\n", ft_atoi(&av[j][i]));
                    addfront(stack, ft_atoi((&av[j][i])));
                    i += (k - 1);
                }
                i++;
//                ft_printf("we're now on the char [%c] of the current argument. Next one is [%c].\n", av[j][i], av[j][i + 1]);
        }
        j++;
    }
    return (stack);
}