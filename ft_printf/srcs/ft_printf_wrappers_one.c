/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wrappers_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:15:41 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:15:44 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrapper_c(va_list *ap)
{
	ft_putchar(va_arg(*ap, int));
	return (1);
}

int	wrapper_s(va_list *ap)
{
	return (ft_putstr(va_arg(*ap, char *)));
}

int	wrapper_i(va_list *ap)
{
	return (ft_putnbr_base(va_arg(*ap, int), "0123456789"));
}

int	wrapper_p(va_list *ap)
{
	write(1, "0x", 2);
	return (2 + ft_putptr((size_t)va_arg(*ap, void *), "0123456789abcdef"));
}
