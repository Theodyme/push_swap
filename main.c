#include "push_swap.h"

int     main(int ac, char **av)
{
    static s_list   *a = NULL;

    if(ac == 1)
    {
        return (0);
    }
    stackbuilder(av, &a);
    stackprinter(&a);
    return (0);
}