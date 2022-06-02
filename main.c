/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/02 17:04:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch(t_list **a, t_list **b)
{
	if (get_size(a) == 2)
		sort_two(a);
	else if (get_size(a) == 3)
		sort_three(a);
	else if (get_size(a) == 5)
		sort_five(a, b);
	return ;
}

void	sort_large(t_list **a, t_list **b)
{
	int	cost;

	cost = 0;
	quicksort(a, b);
	if ((*a)->content > (*a)->next->content)
		i_swap(a, 'a');
	while ((*b) != NULL)
		insertsort(a, b);
	cost = cost_to_top(a, get_min(a));
	rot_to_i(a, 'a', cost);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*tofree;

	tmp = (*stack);
	while (tmp && tmp->next != (*stack))
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
	}
	free(tmp);
}

int	main(int ac, char **av)
{
	static t_list	*a = NULL;
	static t_list	*b = NULL;
	int				check;

	if (ac == 1 || argchecker(av) == 0)
		return (0);
	check = stackbuilder(av, &a);
	if (dupchecker(&a) == 1 || check == 0)
	{
		ft_printf("Error\n");
		free_stack(&a);
		return (0);
	}
	if ((checker(&a, &b)) == 1)
	{
		free_stack(&a);
		return (1);
	}
	if (get_size(&a) == 2 || get_size(&a) == 3 || get_size(&a) == 5)
		dispatch(&a, &b);
	else
		sort_large(&a, &b);
	free_stack(&a);
}
