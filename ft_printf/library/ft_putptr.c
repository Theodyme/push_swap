/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:12:31 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:12:34 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_putptr(size_t hex, char *base)
{
	int				cnt;

	cnt = 0;
	if (hex >= 16)
		cnt += ft_putptr(hex / 16, base);
	ft_putchar(base[(hex % 16)]);
	cnt++;
	return (cnt);
}
