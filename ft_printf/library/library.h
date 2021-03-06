/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:11 by flplace           #+#    #+#             */
/*   Updated: 2022/02/17 15:50:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <unistd.h>

int				ft_checkbase(char *base);
int				ft_putnbr_uint(unsigned int nbr);
int				ft_putptr(size_t hex, char *base);
int				ft_putstr(char *s);
int				ft_putnbr_base(int nbr, char *base);
int				ft_putnbr_hex(unsigned int n, char *base);
void			ft_putchar(char c);
size_t			ft_strlen(const char *str);

#endif
