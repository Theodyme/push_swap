/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:12 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 19:23:49 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch(int ac, t_list **a, t_list **b)
{
	if(ac == 3)
		sort_two(a);
	else if(ac == 4)
		sort_three(a);
	else if(ac == 6)
		sort_five(a, b);
	return ;
}

int		main(int ac, char **av)
{
	static t_list	*a = NULL;
	static t_list	*b = NULL;
	int						cost;

	cost = 0;
	if(ac == 1)
		return (0);
	stackbuilder(av, &a);
	if (dupchecker(&a) == 1)
	{
		return (0);
	}
	if ((checker(&a, &b)) == 1)
		return (1);
	if (ac == 3 || ac == 4 || ac == 6)
		dispatch(ac, &a, &b);
	else
	{
		quicksort(&a, &b);
		if (a->content > a->next->content)
			i_swap(&a, 'a');
		while (b != NULL)
			insertsort(&a, &b);
		cost = cost_to_top(&a, get_min(&a));
		rot_to_i(&a, 'a', cost);
	}
	return (0);
}
