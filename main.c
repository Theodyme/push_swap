#include "push_swap.h"

void    dispatch(int ac, s_list **a, s_list **b)
{
    if(ac == 3)
        sort_two(a);
    else if(ac == 4)
        sort_three(a);
    else if(ac == 6)
        sort_five(a, b);
    stackprinter(a, 'a');
    return ;
}

int     main(int ac, char **av)
{
    static struct s_list   *a = NULL;
    static struct s_list   *b = NULL;

    (void)b;

    if(ac == 1)
        return (0);
    stackbuilder(av, &a);
    if (dupchecker(&a) == 1)
        return (0);
    if ((checker(&a, &b)) == 1)
        return (1);
    if (ac == 3 || ac == 4 || ac == 6)
        dispatch(ac, &a, &b);
    else
    {
        quicksort(&a, &b);
        if (a->content > a->next->content)
            i_swap(&a, 'a');
        while (b)
            insertsort(&a, &b);
    }
    
    if ((checker(&a, &b)) == 1)
        return (1);
    return (0);
}

/*

REVOIR LE CHECKER
To write:
    X Sort_three
    X Sort_five
    X Check if the pile is sorted
Quick sort:
    X A function that gives the biggest number
    X A function that set indexes
    X A function that gives the size of the stack
    X A function that gives the median index
    X A function that iterates on stack A
      to push to B if the number is inferior to the median
Insert sort:
to do > add a "cost" variable to my linked list
        globally testing for each number in B what it costs to push to A
    - a function that recalculate this variable for each node in the list using rot_cost
    - a function that finds the closest sup number (using substraction)
*/