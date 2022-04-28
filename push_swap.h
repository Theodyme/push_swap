#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/srcs/ft_printf.h"

typedef struct s_list
{
    struct s_list   *prev;
	int			content;
	struct s_list	*next;
}           s_list;

int	ft_atoi(const char *str);
int	ft_isdigit(int n);
int	ft_isspace(char c);
void    stackprinter(s_list **stack);
void    addback(s_list **stack, int nbr);


#endif