#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/srcs/ft_printf.h"

typedef struct s_list
{
    struct s_list   *prev;
	int			content;
	struct s_list	*next;
}          		s_list;

int				dupchecker(s_list **stack);
int				ft_atoi(const char *str);
int				ft_isdigit(int n);
int				ft_isspace(char c);
int			    i_push(s_list **from, s_list **to, char cto);
int			    i_reverser(s_list **stack, char flag);
int     		i_rotate(s_list **stack, char flag);
int     		i_swap(s_list **stack, char flag);
void    		stackprinter(s_list **stack, char flag);
void    		addback(s_list **stack, int nbr);
void  			addfront(s_list **stack, int nbr);
struct s_list   **stackbuilder(char **av, s_list **stack);


#endif