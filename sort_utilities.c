/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:01:53 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 19:31:58 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **stack)
{
	int		max;
	t_list	*tmp;

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

	med = (get_size(stack) / 2);
	if (((med % 2) != 0) && med != 1)
		med += 1;
	return (med);
}

void	is_double(t_list **a, t_list **b, t_list **nearest, t_list **target)
{
	if ((*a) != (*nearest) && (*b) != (*target) && ((*nearest)->cost * (*target)->cost) > 0)
	{
		while (((*target)->cost < 0) && ((*nearest)->cost < 0))
		{
			i_double(a, b, 'r');
			(*target)->cost++;
			(*nearest)->cost++;
		}
		while (((*target)->cost > 0) && ((*nearest)->cost > 0))
		{
			i_double(a, b, 'v');
			(*target)->cost--;
			(*nearest)->cost--;
		}
	}
	return ;
}
