/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/06/04 22:51:27 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

# define ERROR_INVALID "Invalid input."
# define ERROR_SIZE "A number is outside the allowed range for integers."
# define ERROR_DOUBLE "A number cannot occur twice."

typedef struct s_node
{
	int				data;
	
	int				index;
	int				push_cost;
	int				above_median;
	struct s_node	*target;
	
	struct s_node	*next;
}	t_node;

typedef struct s_vars
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args_str;
	int		n_args;
	int		og_argc;
}	t_vars;

//utils
int		matrix_len(char **matrix);
int		is_whitespace(char c);
void	display_stacks(t_node *head_a, t_node *head_b);
void	ft_error(t_vars *vars, char *message);
void	init_vars(t_vars *vars, int argc, char *argv[]);

//list_utils_0
void	insert_in_stack(t_node **head, int value);
t_node	*find_last_node(t_node *head);
int		list_size(t_node *head);
t_node *find_biggest(t_node *head);
t_node *find_smallest(t_node *head);

//list_utils_1
t_node *find_smallest_bigger(t_node *head, int data);
t_node *find_cheapest(t_node *head);
t_node *find_closest_smaller(t_node *head, int data);
int	check_sorting(t_node *head);

//input_checks
void	check_and_push(t_vars *vars);

//moves
void	swap(t_node **head, char stack, int print);
void	push(t_node **head_a, t_node **head_b, char stack, int print);
void	rotate(t_node **head, char stack, int print);
void	rrotate(t_node **head, char stack, int print);
void	do_both(t_node **head_a, t_node **head_b, char *move);

//free
void	free_all(t_vars *vars);
void	free_matrix(char **matrix);
void	free_stack(t_node **head);

//sort
void	sort(t_vars *vars);

//node_meta
void	reload_meta_a(t_vars *vars);
void	reload_meta_b(t_vars *vars);
void	set_index(t_node **head);
void	cost_analysis_a(t_vars *vars);

//smart_moves
void	move_a_to_b(t_vars *vars);
void	move_b_to_a(t_vars *vars);
void	move_up(t_node **head, t_node *to_top, char stack);

#endif