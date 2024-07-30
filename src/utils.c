/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/07/30 22:52:18 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(t_vars *vars, char *message)
{
	ft_putendl_fd("Error!", 2);
	ft_putendl_fd(message, 2);
	free_all(vars);
	exit(1);
}

void	set_target_in_a(t_vars *vars)
{
	t_node	*current_b;
	t_node	*smallest_bigger;

	current_b = vars->stack_b;
	while (current_b)
	{
		smallest_bigger = find_smallest_bigger(vars->stack_a, current_b->data);
		if (smallest_bigger)
			current_b->target = smallest_bigger;
		else
			current_b->target = find_smallest(vars->stack_a);
		current_b = current_b->next;
	}
}

void	set_target_in_b(t_vars *vars)
{
	t_node	*current_a;
	t_node	*closest_smaller;

	current_a = vars->stack_a;
	while (current_a)
	{
		closest_smaller = find_closest_smaller(vars->stack_b, current_a->data);
		if (closest_smaller)
			current_a->target = closest_smaller;
		else
			current_a->target = find_biggest(vars->stack_b);
		current_a = current_a->next;
	}
}

/*
void	display_stacks(t_node *head_a, t_node *head_b)
{
	t_node	*current;
	
	current = NULL;
	ft_printf("\nSTACK A:\n");
	if (head_a != NULL)
	{
		current = head_a;
		while(current)
		{
			ft_printf("[%d] ", current->data);
			current = current->next;
		}
	}
	ft_printf("\n");
	ft_printf("STACK B:\n");
	if (head_b != NULL)
	{
		current = head_b;
		while(current)
		{
			ft_printf("[%d] ", current->data);
			current = current->next;
		}
	}
}
*/