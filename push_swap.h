/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:06:17 by flplace           #+#    #+#             */
/*   Updated: 2022/06/02 17:01:05 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/srcs/ft_printf.h"

typedef struct s_list
{
	struct s_list	*prev;
	int				index;
	int				content;
	int				cost;
	struct s_list	*next;
}				t_list;

/*		Sorting main functions			*/
void		dispatch(t_list **a, t_list **b);
void		sort_large(t_list **a, t_list **b);
void		sort_five(t_list **a, t_list **b);
void		sort_three(t_list **stack);
void		sort_two(t_list **stack);

/*		Quicksort						*/
void		quicksort(t_list **a, t_list **b);
int			rot_cost(t_list **stack, int index);
void		rot_to_i(t_list **stack, char flag, int cost);

/*		Insertsort						*/
int			cost_to_top(t_list **stack, int i);
void		fill_costs(t_list **a, t_list **b);
t_list		*find_nearest(t_list **a, int i);
void		insertsort(t_list **a, t_list **b);
void		exec_rotation(t_list **stack, t_list **pin, char flag);
void		is_double(t_list **a, t_list **b, t_list **near, t_list **target);
int			cost_to_top(t_list **stack, int i);
void		executing_costs(t_list **a, t_list **b, t_list **near, t_list **to);

/*		Instructions functions			*/
void		i_push(t_list **from, t_list **to, char cto);
void		i_reverser(t_list **stack, char flag);
void		i_rotate(t_list **stack, char flag);
void		i_swap(t_list **stack, char flag);
void		i_double(t_list **a, t_list **b, char flag);

/*		Index utilities functions		*/
void		fill_tab(int *tab, t_list **stack);
void		sort_index(t_list **stack);
void		sort_tab(int *tab, int size);

/*		Sort utilities functions		*/
int			get_max(t_list **stack);
int			get_min(t_list **stack);
int			get_med(t_list **stack);
int			get_size(t_list **stack);

/* Format checker utilities functions 	*/
int			argchecker(char **av);
int			checker(t_list **a, t_list **b);
int			check_utility(char *av);
int			numchecker(char *str);
int			dupchecker(t_list **stack);

/*		Stack utilities functions		*/
void		addback(t_list **stack, int nbr);
void		free_stack(t_list **stack);
void		addfront(t_list **stack, int nbr);
int			stackbuilder(char **av, t_list **stack);

/*		Library							*/
long int	ft_atol(char *str);
int			ft_abs(int i);
int			ft_atoi(const char *str);
int			ft_isempty(char *av);
int			ft_isalpha(int n);
int			ft_isdigit(int n);
int			ft_isspace(char c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);

#endif
