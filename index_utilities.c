/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:50:44 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 13:52:10 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_index(s_list **stack)
{
	struct s_list	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tab = (int *)ft_calloc(sizeof(int), get_size(stack));
	tmp = (*stack);
	fill_tab(tab, stack);
	sort_tab(tab, (get_size(stack)));
	while (tmp->next != (*stack))
	{
		while (tab[i] && tmp->content != tab[i])
			i++;
		tmp->index = i + 1;
		i = 0;
		tmp = tmp->next;
	}
	while (tab[i] && tmp->content != tab[i])
		i++;
	tmp->index = i + 1;
	free(tab);
	return ;
}

void	fill_tab(int *tab, s_list **stack)
{
	int		i;
	struct s_list	*tmp;

	i = 0;
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	tab[i] = tmp->content;
	return ;
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return ;
}
