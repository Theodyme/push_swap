/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:12 by flplace           #+#    #+#             */
/*   Updated: 2022/06/01 05:17:52 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch(int ac, t_list **a, t_list **b)
{
	if (ac == 3)
		sort_two(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac == 6)
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
	while (tmp->next != (*stack))
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

	if (ac == 1 || ft_isempty(av[1]))
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
	if (ac == 3 || ac == 4 || ac == 6)
		dispatch(ac, &a, &b);
	else
		sort_large(&a, &b);
	free_stack(&a);
}
