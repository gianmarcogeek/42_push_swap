/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/22 02:07:18 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_node *head)
{
	t_node *current;
	int i;
	
	current = head;
	while(current)
	{
		current->index = i++;
		current = current->next;
	}
}
static void	set_target_in_a(t_vars *vars, t_node *current_b)
{
	t_node *smallest_bigger;
	
	smallest_bigger = find_smallest_bigger(vars->stack_a, current_b->data);
	if(smallest_bigger)
		current_b->target = smallest_bigger;
	else
	current_b->target = find_smallest(vars->stack_a);
}

void	set_cost(t_vars *vars)
{
	int size_a;
	int size_b;
	t_node *current_b;
	
	current_b = vars->stack_b;
	while(current_b)
	{
		size_a = list_size(vars->stack_a);
		size_b = list_size(vars->stack_b);
		set_target_in_a(vars, current_b);
		if (current_b->index < size_b / 2)
		{
			current_b->above_median = 1;
			current_b->push_cost = size_b - current_b->index;
		}
		if (current_b->target->index < size_a / 2)
		{
			current_b->target->above_median = 1;
			current_b->push_cost = current_b->target->index;
		}
		else
			current_b->push_cost += size_a - current_b->target->index;
		current_b = current_b->next;
	}
}
