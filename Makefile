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

SRCS	=	 delete_this.c \
			instructions.c \
			stack_utilities.c \
			library/ft_atoi.c \
			main.c \

LIB		=	ft_printf/libftprintf.a

OBJ		= ${SRCS:.c=.o}

NAME	= pushswap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o: 	%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJ}
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

all:	${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
