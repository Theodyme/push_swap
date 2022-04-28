/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:13 by flplace           #+#    #+#             */
/*   Updated: 2022/02/14 18:10:52 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../library/library.h"
# include <unistd.h>

typedef int	(*t_type)(va_list *ap);

typedef struct t_fn
{
	char	flag;
	t_type	function;
}		t_fn;

int	ft_printf(const char *input, ...);
int	ft_process_args(va_list *ap, char flag);
int	wrapper_c(va_list *ap);
int	wrapper_i(va_list *ap);
int	wrapper_lx(va_list *ap);
int	wrapper_p(va_list *ap);
int	wrapper_s(va_list *ap);
int	wrapper_u(va_list *ap);
int	wrapper_ux(va_list *ap);

#endif
