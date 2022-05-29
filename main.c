#include "push_swap.h"

int     main(int ac, char **av)
{
    static struct s_list   *a = NULL;
    static struct s_list   *b = NULL;

    // int *tab;
    // tab = calloc(sizeof(int), 5);
    // arrayprinter(tab);

    (void)b;

    if(ac == 1)
        return (0);
    stackbuilder(av, &a);
    if (dupchecker(&a) == 1)
        return (0);
    if ((checker(&a)) == 1)
        return (1);
    if(ac == 3)
        sort_two(&a);
    else if(ac == 4)
        sort_three(&a);
    // else if(ac == 6)
    //     sort_five(&a, &b);
    // else
    //     quicksort(&a, &b);
    // i_push(&b, &a, 'a');

    // get_med(&a);
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&b, &a, 'a');
    i_push(&b, &a, 'a');
    i_push(&b, &a, 'a');
    i_push(&b, &a, 'a');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    // // set_index(&a);
    // // set_index(&b);
    // get_med(&a);
    // get_med(&b);
    // indexprinter(&a, 'a');
    // indexprinter(&b, 'b');
    return (0);
}

/*
To write:
    X Sort_three
    - Sort_five
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
    - a function that recalculate this variable for each node in the list using rot_cost
    - a function that finds the closest sup number (using substraction)

    - A function that push to A
*/