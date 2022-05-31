/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:02:26 by flplace           #+#    #+#             */
/*   Updated: 2022/05/31 23:57:22 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	i_swap(t_list **stack, char flag)
{
	int	tmp;

	tmp = (*stack)-> content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (flag)
		ft_printf("s%c\n", flag);
	return ;
}

void	i_push(t_list **from, t_list **to, char flag)
{
	t_list	*tofree;

	tofree = (*from);
	addfront(to, (*from)->content);
	if (get_size(from) == 1)
	{
		ft_printf("p%c\n", flag);
		free(tofree);
		(*from) = NULL;
		return ;
	}
	(*from)->prev->next = (*from)->next;
	(*from)->next->prev = (*from)->prev;
	(*from) = (*from)->next;
	free(tofree);
	ft_printf("p%c\n", flag);
	return ;
}

void	i_rotate(t_list **stack, char flag)
{
	(*stack) = (*stack)->next;
	if (flag)
		ft_printf("r%c\n", flag);
	return ;
}

void	i_reverser(t_list **stack, char flag)
{
	(*stack) = (*stack)->prev;
	if (flag)
		ft_printf("rr%c\n", flag);
	return ;
}

void	i_double(t_list **a, t_list **b, char flag)
{
	if (flag == 's')
	{
		i_swap(a, '\0');
		i_swap(b, '\0');
		ft_printf("ss\n");
	}
	if (flag == 'r')
	{
		i_rotate(a, '\0');
		i_rotate(b, '\0');
		ft_printf("rr\n");
	}
	if (flag == 'v')
	{
		i_reverser(a, '\0');
		i_reverser(b, '\0');
		ft_printf("rrr\n");
	}
	return ;
}
