#include "push_swap.h"

int     main(int ac, char **av)
{
    static struct s_list   *a = NULL;
    static struct s_list   *b = NULL;

    if(ac == 1)
    {
        return (0);
    }
    stackbuilder(av, &a);
    get_size(&a);
    if (dupchecker(&a) == 1)
        return (0);
    if ((checker(&a)) == 1)
        return (1);
    if(ac == 3)
    {
        (void)b;
        sort_two(&a);
    }
    if(ac == 4)
    {
        (void)b;
        sort_three(&a);
    }
    get_med(&a);
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    set_index(&a);
    set_index(&b);
    get_med(&a);
    get_med(&b);
    indexprinter(&a, 'a');
    indexprinter(&b, 'b');
    return (0);
}

/*
To write:
    - Sort_three
    - Sort_five
    X Check if the pile is sorted
Quick sort:
    X A function that gives the biggest number
    X A function that set indexes
    - A function that gives the median index
    - A function that iterates on stack A
      to push to B if the number is inferior to the median
Insert sort:
    - A function that search for the closest superior number
    - A function that gives which way it should rotate
*/