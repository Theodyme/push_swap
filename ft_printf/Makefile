# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flplace <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 12:20:26 by flplace           #+#    #+#              #
#    Updated: 2021/01/22 16:09:58 by flplace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_printf.c \
		srcs/ft_printf_wrappers_one.c \
		srcs/ft_printf_wrappers_two.c \
		library/ft_putchar.c \
		library/ft_putstr.c \
		library/ft_putptr.c \
		library/ft_putnbr_base.c \
		library/ft_putnbr_hex.c \
		library/ft_strlen.c \
		library/ft_checkbase.c \
		library/ft_putnbr_uint.c \

OBJ	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o: 	%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJ}
	ar rc ${NAME} ${OBJ}

all:	${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
