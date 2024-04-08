/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 10:43:52 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <stdbool.h>

# define ERROR_INVALID "Only numbers in base 10 accepted."
# define ERROR_SIZE "A number is outside the allowed range for integers."
# define ERROR_DOUBLE "A number cannot occur twice."

typedef struct s_node
{
	int				data;

	struct s_node	*next;
}	t_node;

//utils
int		ft_splitlen(char **matrix);
void	display_stacks(t_node *stack_a, t_node *stack_b);

//check_and_init
void	check_and_init(t_node **list, char **args, int n_args);
bool	check_number(char *arg);
void	insert_in_stack(t_node **head, int value);
t_node	*find_last_node(t_node *head);

//check_for_dup
bool	check_for_dup(t_node *head);

//ft_error
void	ft_error(char *message);

//operations
void	swap(t_node **lst, char stack, bool print);
void	push(t_node **stack_a, t_node **stack_b, char stack, bool print);
void	rotate(t_node **lst, char stack, bool print);
void	rrotate(t_node **lst, char stack, bool print);
void	do_both(t_node **stack_a, t_node **stack_b, char *move);
#endif