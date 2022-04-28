/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:12:12 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:12:14 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putnbr_uint(unsigned int nbr)
{
	int				cnt;

	cnt = 0;
	if (nbr >= 10)
		cnt += ft_putnbr_uint(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	cnt++;
	return (cnt);
}
