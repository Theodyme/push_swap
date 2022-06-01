/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:01:20 by flplace           #+#    #+#             */
/*   Updated: 2022/06/01 04:26:53 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(t_list **stack, int i)
{
	int		up;
	int		down;
	t_list	*tmp;

	up = 1;
	down = 0;
	tmp = (*stack)->prev;
	while (tmp->prev != (*stack))
	{
		if (tmp->content == i)
			break ;
		tmp = tmp->prev;
		up++;
	}
	down = (get_size(stack) - up);
	if ((*stack)->content == i)
		return (0);
	if (down < up)
		return (down * (-1));
	else
		return (up);
}

int	numchecker(char *str)
{
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	else
		return (1);
}

int	ft_isempty(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(ft_isspace(av[i])))
			return (0);
		i++;
	}
	ft_printf("Error\n");
	return (1);
}

int	ft_isalpha(int n)
{
	if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
		return (1);
	return (0);
}

int	avcheck(char *av, t_list **stack)
{
	int	i;
	int	k;

	i = -1;
	while (av[++i])
	{
		k = 0;
		if ((ft_isalpha(av[i])) == 1)
			return (0);
		while ((av[i] && ft_isdigit(av[i + k]) == 1) || av[i + k] == '-')
			k++;
		if (k != 0)
		{
			if (numchecker(av) == 0)
				return (0);
			addback(stack, ft_atoi(&av[i]));
			i += (k - 1);
		}
	}
	return (1);
}
