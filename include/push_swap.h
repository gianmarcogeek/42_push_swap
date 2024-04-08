/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 18:09:39 by gpuscedd         ###   ########.fr       */
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
int		matrix_len(char **matrix);
void	display_stacks(t_node *head_a, t_node *head_b);
void	ft_error(char *message);

//list_utils
void	insert_in_stack(t_node **head, int value);
t_node	*find_last_node(t_node *head);

//input_checks
void	check_and_init(t_node **head, char **args, int n_args);
bool	check_number(char *arg);
bool	check_for_dup(t_node *head);
//moves
void	swap(t_node **head, char stack, bool print);
void	push(t_node **head_a, t_node **head_b, char stack, bool print);
void	rotate(t_node **head, char stack, bool print);
void	rrotate(t_node **head, char stack, bool print);
void	do_both(t_node **head_a, t_node **head_b, char *move);

//free
void	free_all(t_node **head_a, t_node **head_b, char **matrix, int argc);
void	free_matrix(char **matrix);
void	free_stack(t_node **head);

#endif