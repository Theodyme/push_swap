/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:29 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 23:26:08 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_nearest(t_list **a, int i)
{
	int		current;
	t_list	*tmp;
	int		lowest;
	t_list	*sup;

	sup = (*a);
	lowest = (*a)->content;
	tmp = (*a)->next;
	while (tmp != (*a))
	{
		current = tmp->content;
		if (((lowest < i) && (current < lowest))
			|| ((lowest < i) && (current > i))
			|| ((current > i) && (current < lowest)))
		{
			sup = tmp;
			lowest = current;
		}
		tmp = tmp->next;
	}
	return (sup);
}

void	fill_costs(t_list **a, t_list **b)
{
	t_list	*tmp;

	if ((*b) == NULL || get_size(b) == 0)
		return ;
	tmp = (*b);
	while (tmp->next != (*b))
	{
		tmp->cost = cost_to_top(b, tmp->content);
		tmp = tmp->next;
	}
	tmp->cost = cost_to_top(b, tmp->content);
	tmp = (*a);
	while (tmp->next != (*a))
	{
		tmp->cost = cost_to_top(a, tmp->content);
		tmp = tmp->next;
	}
	tmp->cost = cost_to_top(a, tmp->content);
	return ;
}

void	executing_costs(t_list **a, t_list **b, t_list **near, t_list **targ)
{
	is_double(a, b, near, targ);
	if ((*a) != (*near) || (*b) != (*targ))
	{
		exec_rotation(a, near, 'a');
		exec_rotation(b, targ, 'b');
	}
	return ;
}

void	exec_rotation(t_list **stack, t_list **pin, char flag)
{
	if ((*stack) != (*pin))
	{
		while ((*pin)->cost < 0)
		{
			i_rotate(stack, flag);
			(*pin)->cost++;
		}
		while ((*pin)->cost != 0)
		{
			i_reverser(stack, flag);
			(*pin)->cost--;
		}
	}
	return ;
}

void	insertsort(t_list **a, t_list **b)
{
	int		lowest;
	t_list	*target;
	t_list	*nearest;
	t_list	*btmp;

	fill_costs(a, b);
	target = (*b);
	nearest = find_nearest(a, (*b)->content);
	lowest = ft_abs((*b)->cost) + ft_abs(nearest->cost);
	btmp = (*b)->next;
	while (btmp->next != (*b))
	{
		if (lowest > (ft_abs(btmp->cost)
				+ ft_abs((find_nearest(a, btmp->content))->cost)))
		{
			lowest = ft_abs((find_nearest(a, btmp->content))->cost);
			nearest = find_nearest(a, btmp->content);
			target = btmp;
		}
		btmp = btmp->next;
	}
	executing_costs(a, b, &nearest, &target);
	i_push(b, a, 'a');
	return ;
}
