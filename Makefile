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
			sorting_small.c \
			instructions.c \
			index_utilities.c \
			quicksort.c \
			sort_utilities.c \
			stack_utilities.c \
			library/ft_atoi.c \
			library/ft_calloc.c \
			main.c \

LIB		=	ft_printf/libftprintf.a

OBJ		= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o: 	%.c
	${CC} ${CFLAGS} -g -c $< -o $@

$(NAME):	${OBJ}
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

all:	${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
