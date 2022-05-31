/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:04:44 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 19:16:52 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackprinter(t_list **stack, char flag)
{
	t_list	*tmp;

	if ((*stack) == NULL)
	{
		ft_printf("%c stack is empty. ", flag);
		return ;
	}
	tmp = *stack;
	ft_printf("%c stack content (from top to bottom) : ", flag);
	while (tmp->next != *stack)
	{
		ft_printf("%d, ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->content);
	return ;
}

void	backprinter(t_list **stack, char flag)
{
	t_list	*tmp;

	if ((*stack) == NULL)
	{
		ft_printf("%c stack is empty. ", flag);
		return ;
	}
	tmp = (*stack)->prev;
	ft_printf("%c stack content from prev (from top to bottom) : ", flag);
	while (tmp != *stack)
	{
		ft_printf("%d, ", tmp->content);
		tmp = tmp->prev;
	}
	ft_printf("%d\n", tmp->content);
	return ;
}

void	arrayprinter(int *tab)
{
	int	i;

	i = 0;
	ft_printf("The array contains the following numbers: ");
	while (tab[i + 1])
	{
		ft_printf("%d, ", tab[i]);
		i++;
	}
	ft_printf("%d.\n", tab[i]);
	return ;
}

void	indexprinter(t_list **stack, char flag)
{
	t_list	*tmp;

	if ((*stack) == NULL)
	{
		ft_printf("%c stack is empty. ", flag);
		return ;
	}
	tmp = *stack;
	ft_printf("%c stack index (from top to bottom) : ", flag);
	while (tmp->next != *stack)
	{
		ft_printf("%d, ", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->index);
	return ;
}

void	costprinter(t_list **stack, char flag)
{
	t_list	*tmp;

	if ((*stack) == NULL)
	{
		ft_printf("%c stack is empty. ", flag);
		return ;
	}
	tmp = *stack;
	ft_printf("%c stack cost (from top to bottom) : ", flag);
	while (tmp->next != *stack)
	{
		ft_printf("%d, ", tmp->cost);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->cost);
	return ;
}
