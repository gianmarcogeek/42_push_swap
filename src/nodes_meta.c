/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/07/30 22:49:28 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reload_meta_a(t_vars *vars)
{
	set_index(&vars->stack_a);
	set_index(&vars->stack_b);
	set_target_in_b(vars);
	cost_analysis_a(vars);
}

void	reload_meta_b(t_vars *vars)
{
	set_index(&vars->stack_a);
	set_index(&vars->stack_b);
	set_target_in_a(vars);
}

void	set_index(t_node **head)
{
	t_node	*current;
	int		i;
	int		half;

	if (!*head)
		return ;
	current = *head;
	i = 0;
	half = list_size(*head) / 2;
	while (current)
	{
		current->index = i++;
		if (i <= half)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
	}
}

void	cost_analysis_a(t_vars *vars)
{
	int		len_a;
	int		len_b;
	t_node	*current_a;

	len_a = list_size(vars->stack_a);
	len_b = list_size(vars->stack_b);
	current_a = vars->stack_a;
	while (current_a)
	{
		current_a->push_cost = current_a->index;
		if (!(current_a->above_median))
			current_a->push_cost = len_a - current_a->index;
		if (current_a->target->above_median)
			current_a->push_cost += current_a->target->index;
		else
			current_a->push_cost += len_b - current_a->target->index;
		current_a = current_a->next;
	}
}
