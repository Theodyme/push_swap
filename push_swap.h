#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/srcs/ft_printf.h"

typedef struct s_list
{
    struct s_list   *prev;
	int			index;
	int			content;
	struct s_list	*next;
}          		s_list;

/*		Sorting main functions		*/
void	sort_five(s_list **a, s_list **b);
void	sort_three(s_list **stack);
void	sort_two(s_list **stack);

/*		Quicksort					*/
void    quicksort(s_list **a, s_list **b);
int    	rot_cost(s_list **stack, int index);
void    rot_to_i(s_list **stack, char flag, int cost);

/*		Instructions functions		*/
int	    i_push(s_list **from, s_list **to, char cto);
int	    i_reverser(s_list **stack, char flag);
int    	i_rotate(s_list **stack, char flag);
int     i_swap(s_list **stack, char flag);

/*		Index utilities functions	*/
void    fill_tab(int *tab, s_list **stack);
void    sort_index(s_list **stack);
void	sort_tab(int *tab, int size);
// void    set_index(s_list **stack);

/*		Sort utilities functions	*/
int    	get_max(s_list **stack);
int     get_min(s_list **stack);
int    	get_med(s_list **stack);
int    	get_size(s_list **stack);

/*		Stack utilities functions	*/
int		checker(s_list **stack);
int		dupchecker(s_list **stack);
void   	addback(s_list **stack, int nbr);
void  	addfront(s_list **stack, int nbr);
void   	stackbuilder(char **av, s_list **stack);

/*		Library						*/
int		ft_atoi(const char *str);
int		ft_isdigit(int n);
int		ft_isspace(char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

//	THOSE NEEDS TO BE DELETED BEFORE SETTING AS FINISHED
void    arrayprinter(int *tab);
void    stackprinter(s_list **stack, char flag);
void    indexprinter(s_list **stack, char flag);

#endif