/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:01:53 by flplace           #+#    #+#             */
/*   Updated: 2022/06/01 04:49:07 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **stack)
{
	int		max;
	t_list	*tmp;

	if (!(*stack))
		return (0);
	max = (*stack)->content;
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	if (max < tmp->content)
		max = tmp->content;
	return (max);
}

int	get_min(t_list **stack)
{
	int		min;
	t_list	*tmp;

	if (!(*stack))
		return (0);
	min = (*stack)->content;
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	if (min > tmp->content)
		min = tmp->content;
	return (min);
}

int	get_size(t_list **stack)
{
	int		size;
	t_list	*tmp;

	if (!(*stack))
		return (0);
	size = 0;
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		size++;
		tmp = tmp->next;
	}
	size++;
	return (size);
}

int	get_med(t_list **stack)
{
	int		med;

	if (!(*stack))
		return (0);
	med = (get_size(stack) / 2);
	if (((med % 2) != 0) && med != 1)
		med += 1;
	return (med);
}

void	is_double(t_list **a, t_list **b, t_list **near, t_list **target)
{
	if ((*a) != (*near) && (*b) != (*target)
		&& ((*near)->cost * (*target)->cost) > 0)
	{
		while (((*target)->cost < 0) && ((*near)->cost < 0))
		{
			i_double(a, b, 'r');
			(*target)->cost++;
			(*near)->cost++;
		}
		while (((*target)->cost > 0) && ((*near)->cost > 0))
		{
			i_double(a, b, 'v');
			(*target)->cost--;
			(*near)->cost--;
		}
	}
	return ;
}
