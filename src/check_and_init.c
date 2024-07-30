/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:41:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/07/30 22:48:36 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_for_dup(t_vars *vars)
{
	t_node	*current;
	t_node	*compare;

	current = vars->stack_a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->data == compare->data)
				ft_error(vars, ERROR_DOUBLE);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

void	check_and_push(t_vars *vars)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (i < vars->n_args)
	{
		if (check_number(vars->args_str[i]))
		{
			number = ft_atoll(vars->args_str[i]);
			if ((number >= INT_MIN && number <= INT_MAX) && \
				!(ft_strlen(vars->args_str[i]) > 10))
				insert_in_stack(&vars->stack_a, number);
			else
				ft_error(vars, ERROR_SIZE);
		}
		else
			ft_error(vars, ERROR_INVALID);
		i++;
	}
	check_for_dup(vars);
}

void	init_vars(t_vars *vars, int argc, char *argv[])
{
	vars->stack_a = NULL;
	vars->stack_b = NULL;
	vars->args_str = NULL;
	vars->n_args = 0;
	vars->og_argc = argc;
	if (argc == 2)
	{
		if (argv[1] != NULL && argv[1][0] != '\0' && \
			!ft_iswhitespace(argv[1][0]))
		{
			vars->args_str = ft_split(argv[1], ' ');
			vars->n_args = ft_matlen(vars->args_str);
		}
		else
			exit(1);
	}
	else if (argc > 2)
	{
		vars->args_str = argv + 1;
		vars->n_args = argc - 1;
	}
	else
		exit (1);
}

void	init_meta(t_node **new_node, int value)
{
	(*new_node)->data = value;
	(*new_node)->index = 0;
	(*new_node)->push_cost = 0;
	(*new_node)->above_median = 0;
	(*new_node)->target = NULL;
	(*new_node)->next = NULL;
}
