/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:00 by flplace           #+#    #+#             */
/*   Updated: 2022/06/01 06:12:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		cost;
	int		med;

	while (get_size(a) != 2)
	{
		sort_index(a);
		tmp = (*a);
		med = get_med(a);
		while (tmp->next != (*a) && get_size(a) > 2)
		{
			if (get_size(a) == 3)
			{
				while (tmp->content != get_min(a))
					tmp = tmp->next;
			}
			tmp = tmp->next;
			if ((tmp->index <= med) || (get_size(a) == 3))
			{
				cost = rot_cost(a, tmp->prev->index);
				rot_to_i(a, 'a', cost);
				i_push(a, b, 'b');
			}
		}
	}
}

void	rot_to_i(t_list **stack, char flag, int cost)
{
	if (cost == 0)
		return ;
	if (cost < 0)
	{
		while (cost != 0)
		{
			i_rotate(stack, flag);
			cost++;
		}
	}
	else
	{
		while (cost != 0)
		{
			i_reverser(stack, flag);
			cost--;
		}
	}
	return ;
}

int	rot_cost(t_list **stack, int index)
{
	int		up;
	int		down;
	t_list	*tmp;

	up = 1;
	down = 0;
	tmp = (*stack)->prev;
	while (tmp->prev != (*stack))
	{
		if (tmp->index == index)
			break ;
		tmp = tmp->prev;
		up++;
	}
	down = (get_size(stack) - up);
	if ((*stack)->index == index)
		return (0);
	if (down < up)
		return (down * (-1));
	else
		return (up);
}
