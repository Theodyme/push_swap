#include "push_swap.h"

void    stackprinter(s_list **stack, char flag)
{
    struct s_list  *tmp;

    if ((*stack) == NULL)
    {
        ft_printf("%c stack is empty. ", flag);
        return ;
    }
    tmp = *stack;
    ft_printf("%c stack content (from top to bottom) : ", flag);
    while (tmp->next != *stack)
    {
        ft_printf("%d, ", tmp->content);
        tmp = tmp->next;
    }
    ft_printf("%d\n", tmp->content);
    return ;
}

void    arrayprinter(int *tab)
{
    int i;

    i = 0;
    ft_printf("The array contains the following numbers: ");
    while (tab[i + 1])
    {
        ft_printf("%d, ", tab[i]);
        i++;
    }
    ft_printf("%d.\n", tab[i]);
    return ;
}

void    indexprinter(s_list **stack, char flag)
{
    struct s_list  *tmp;

    if ((*stack) == NULL)
    {
        ft_printf("%c stack is empty. ", flag);
        return ;
    }
    tmp = *stack;
    ft_printf("%c stack index (from top to bottom) : ", flag);
    while (tmp->next != *stack)
    {
        ft_printf("%d, ", tmp->index);
        tmp = tmp->next;
    }
    ft_printf("%d\n", tmp->index);
    return ;
}