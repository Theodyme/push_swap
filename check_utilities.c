/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:02:00 by flplace           #+#    #+#             */
/*   Updated: 2022/06/02 17:05:00 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_utility(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (ft_isdigit(av[i]) == 0 && !(av[i] == '+')
			&& !(av[i] == '-') && !(av[i] == ' '))
			return (0);
		if ((av[i] == '+' && av[i - 1] && ft_isdigit(av[i - 1]) == 1)
			|| (av[i] == '+' && av[i - 1] && av[i - 1] == '+'))
			return (0);
		if ((av[i] == '-' && av[i - 1] && ft_isdigit(av[i - 1]) == 1)
			|| (av[i] == '-' && av[i - 1] && av[i - 1] == '-'))
			return (0);
		if (((av[i] == '-') && av[i - 1] && av[i - 1] == '+')
			|| ((av[i] == '+') && av[i - 1] && av[i - 1] == '-'))
			return (0);
	}
	return (1);
}

int	argchecker(char **av)
{
	int	j;

	j = 0;
	while (av[++j])
	{
		if (check_utility(av[j]) == 0 || ft_isempty(av[j]) == 1)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
