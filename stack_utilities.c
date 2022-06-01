/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:54:46 by flplace           #+#    #+#             */
/*   Updated: 2022/06/01 04:22:29 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list **a, t_list **b)
{
	t_list	*tmp;

	if ((*b))
		return (0);
	if ((*a) && !(*a)->next)
		return (1);
	tmp = (*a);
	while (tmp->next != *a)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	dupchecker(t_list **stack)
{
	t_list	*tmp;
	t_list	*node;
	int		checker;

	node = *stack;
	while (node->next != *stack)
	{
		checker = node->content;
		tmp = node->next;
		while (tmp->next != (*stack)->next)
		{
			if (tmp->content == checker)
				return (1);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (0);
}

void	addback(t_list **stack, int nbr)
{
	t_list	*node;
	t_list	*last;

	node = malloc(sizeof(t_list));
	node->content = nbr;
	if (!*stack)
	{
		node->next = node;
		node->prev = node;
		node->index = 1;
		*stack = node;
		return ;
	}
	last = (*stack)->prev;
	node->next = *stack;
	last->next = node;
	node->prev = last;
	node->index = (node->prev->index + 1);
	(*stack)->prev = node;
	return ;
}

void	addfront(t_list **stack, int nbr)
{
	t_list	*node;
	t_list	*last;

	node = malloc(sizeof(t_list));
	node->content = nbr;
	if (!*stack)
	{
		node->next = node;
		node->prev = node;
		*stack = node;
		return ;
	}
	last = (*stack)->prev;
	node->prev = last;
	node->next = *stack;
	last->next = node;
	(*stack)->prev = node;
	*stack = node;
	return ;
}

int	stackbuilder(char **av, t_list **stack)
{
	int	i;
	int	j;

	j = 0;
	while (av[++j])
	{
		i = avcheck(av[j], stack);
		if (i == 0)
			return (0);
	}
	return (1);
}
