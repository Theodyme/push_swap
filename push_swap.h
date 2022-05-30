#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/srcs/ft_printf.h"

typedef struct s_list
{
    struct s_list   *prev;
	int			index;
	int			content;
	int			cost;
	struct s_list	*next;
}          		s_list;

/*		Sorting main functions		*/
void    dispatch(int ac, s_list **a, s_list **b);
void	sort_five(s_list **a, s_list **b);
void	sort_three(s_list **stack);
void	sort_two(s_list **stack);

/*		Quicksort					*/
void    quicksort(s_list **a, s_list **b);
int    	rot_cost(s_list **stack, int index);
void    rot_to_i(s_list **stack, char flag, int cost);

/*		Insertsort					*/
int		cost_to_top(s_list **stack, int i);
void    fill_costs(s_list **a, s_list **b);
s_list  *find_nearest(s_list **a, int i);
void    insertsort(s_list **a, s_list **b);
void    is_double(s_list **a, s_list **b, s_list **nearest, s_list **target);
void    executing_costs(s_list **a, s_list **b, s_list **target, s_list **nearest);

/*		Instructions functions		*/
void    i_push(s_list **from, s_list **to, char cto);
void    i_reverser(s_list **stack, char flag);
void   	i_rotate(s_list **stack, char flag);
void    i_swap(s_list **stack, char flag);
void    i_double(s_list **a, s_list **b, char flag);

/*		Index utilities functions	*/
void    fill_tab(int *tab, s_list **stack);
void    sort_index(s_list **stack);
void	sort_tab(int *tab, int size);

/*		Sort utilities functions	*/
int    	get_max(s_list **stack);
int     get_min(s_list **stack);
int    	get_med(s_list **stack);
int    	get_size(s_list **stack);

/*		Stack utilities functions	*/
int		checker(s_list **a, s_list **b);
int		dupchecker(s_list **stack);
void   	addback(s_list **stack, int nbr);
void  	addfront(s_list **stack, int nbr);
void   	stackbuilder(char **av, s_list **stack);

/*		Library						*/
int 	ft_abs(int i);
int		ft_atoi(const char *str);
int		ft_isdigit(int n);
int		ft_isspace(char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

//	THOSE NEEDS TO BE DELETED BEFORE SETTING AS FINISHED
void    arrayprinter(int *tab);
void    costprinter(s_list **stack, char flag);
void    backprinter(s_list **stack, char flag);
void    stackprinter(s_list **stack, char flag);
void    indexprinter(s_list **stack, char flag);

#endif