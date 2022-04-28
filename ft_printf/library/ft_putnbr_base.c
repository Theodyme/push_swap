/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:55 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:11:58 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	int				cnt;
	int				baselen;

	cnt = 0;
	n = 0;
	baselen = ft_strlen(base);
	if (ft_checkbase(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			cnt++;
			n = -nbr;
		}
		else
			n = nbr;
		if (n >= (unsigned int)baselen)
			cnt += ft_putnbr_base(n / baselen, base);
		ft_putchar(base[(n % baselen)]);
		cnt++;
	}
	return (cnt);
}
