#include "push_swap.h"

void    quicksort(s_list **a, s_list **b)
{
    struct s_list   *tmp;
    int med;

    while (get_size(a) != 2)
    {
        tmp = (*a);
        med = get_med(a);
        sort_index(a);
        while (tmp->next != (*a))
        {
            if (tmp->index <= med)
            {
                //ROTATE UNTIL AT THE TOP
                i_push(a, b, 'b');
            }
            tmp = tmp->next;
        }
        if (tmp->index <= med)
            i_push(a, b, 'b');
    }
    stackprinter(a, 'a');
    stackprinter(b, 'b');
    return ;

}

void    rot_cost(s_list **stack, int index)
{
    int up;
    int down;



}