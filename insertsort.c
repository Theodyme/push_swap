/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:29 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 19:35:12 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_nearest(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*sup;
	int		lowest;
	int		current;

	tmp = (*a);
	while (tmp->next != (*a) && tmp->content != get_min(a))
		tmp = tmp->next;
	lowest = 0;
	sup = tmp;
	tmp = (*a);
	while (tmp->next != (*a))
	{
		if ((tmp->content > i))
		{
			current = (tmp->content) - i;
			if (((lowest > current) && (lowest != 0)) || lowest == 0)
			{
				lowest = current;
				sup = tmp;
			}
		}
		tmp = tmp->next;
	}
	if ((tmp->content > i))
	{
		current = (tmp->content) - i;
		if (((lowest > current) && (lowest != 0)) || lowest == 0)
		{
			lowest = current;
			sup = tmp;
		}
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

int	cost_to_top(t_list **stack, int i)
{
	int		up;
	int		down;
	t_list	*tmp;

	if (!(*stack))
		return (0);
	up = 1;
	down = 0;
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		if (tmp->content == i)
			break ;
		tmp = tmp->next;
		down++;
	}
	tmp = (*stack)->prev;
	while (tmp->prev != (*stack))
	{
		if (tmp->content == i)
			break ;
		tmp = tmp->prev;
		up++;
	}
	if (down < up)
		return (down * (-1));
	else
		return (up);
}

void	executing_costs(t_list **a, t_list **b, t_list **near, t_list **targ)
{
	is_double(a, b, near, targ);
	if ((*a) != (*near) || (*b) != (*targ))
	{
		while ((*a) != (*near))
		{
			while ((*near)->cost < 0)
			{
				i_rotate(a, 'a');
				(*near)->cost++;
			}
			while ((*near)->cost != 0)
			{
				i_reverser(a, 'a');
				(*near)->cost--;
			}
		}
		while ((*b) != (*targ))
		{
			while ((*targ)->cost < 0)
			{
				i_rotate(b, 'b');
				(*targ)->cost++;
			}
			while ((*targ)->cost != 0)
			{
				i_reverser(b, 'b');
				(*targ)->cost--;
			}
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

	btmp = (*b);
	fill_costs(a, b);
	target = btmp;
	nearest = find_nearest(a, btmp->content);
	lowest = ft_abs(btmp->cost) + ft_abs(nearest->cost);
	btmp = btmp->next;
	while (btmp != (*b))
	{
		if (lowest > (ft_abs(btmp->cost) + ft_abs((find_nearest(a, btmp->content))->cost)))
		{
			lowest = ft_abs((find_nearest(a, btmp->content))->cost);
			nearest = find_nearest(a, btmp->content);
			target = btmp;
		}
		btmp = btmp->next;
	}
	if (lowest > ft_abs(btmp->cost) + ft_abs((find_nearest(a, btmp->content))->cost))
	{
		lowest = ft_abs((find_nearest(a, btmp->content))->cost);
		nearest = find_nearest(a, btmp->content);
		target = btmp;
	}
	executing_costs(a, b, &nearest, &target);
	i_push(b, a, 'a');
	return ;
}
