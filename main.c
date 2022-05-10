#include "push_swap.h"

int     main(int ac, char **av)
{
    static s_list   *a = NULL;
    static s_list   *b = NULL;

    if(ac == 1)
    {
        return (0);
    }
    stackbuilder(av, &a);
    if (dupchecker(&a) == 1)
    {
        return (0);
    }
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_swap(&a,'a');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    i_push(&a, &b, 'b');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_rotate(&a, 'a');
    i_rotate(&b, 'b');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_reverser(&a, 'a');
    i_reverser(&b, 'b');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_swap(&a,'a');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    i_push(&b, &a, 'a');
    i_push(&b, &a, 'a');
    i_push(&b, &a, 'a');
    stackprinter(&a, 'a');
    stackprinter(&b, 'b');
    return (0);
}