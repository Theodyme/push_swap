#include "push_swap.h"

void    dispatch(int ac, s_list **a, s_list **b)
{
    if(ac == 3)
        sort_two(a);
    else if(ac == 4)
        sort_three(a);
    else if(ac == 6)
        sort_five(a, b);
    return ;
}

int     main(int ac, char **av)
{
    static struct s_list   *a = NULL;
    static struct s_list   *b = NULL;
    int                     cost;

    cost = 0;
    if(ac == 1)
        return (0);
    stackbuilder(av, &a);
    if (dupchecker(&a) == 1)
    {
        return (0);
    }
    if ((checker(&a, &b)) == 1)
        return (1);
    if (ac == 3 || ac == 4 || ac == 6)
        dispatch(ac, &a, &b);
    else
    {
        quicksort(&a, &b);
        if (a->content > a->next->content)
            i_swap(&a, 'a');
        while (b != NULL)
            insertsort(&a, &b);
        cost = cost_to_top(&a, get_min(&a));
        rot_to_i(&a, 'a', cost);
    }
	stackprinter(&a, 'a');
	stackprinter(&b, 'b');
    return (0);
}
