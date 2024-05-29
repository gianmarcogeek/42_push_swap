/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/29 19:49:18 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_target_in_a(t_vars *vars)
{
	t_node *current_b;
	t_node *smallest_bigger;
	
	current_b = vars->stack_b;
	smallest_bigger = find_smallest_bigger(vars->stack_a, current_b->data);
	while(current_b)
	{
		if(smallest_bigger)
			current_b->target = smallest_bigger;
		else
		current_b->target = find_smallest(vars->stack_a);
		current_b = current_b->next;
	}
}

static void	set_target_in_b(t_vars *vars)
{
	t_node *current_a;
	t_node *closest_smaller;
	
	current_a = vars->stack_a;
	closest_smaller = find_closest_smaller(vars->stack_b, current_a->data);
	while(current_a)
	{		
		if(closest_smaller)
			current_a->target = closest_smaller;
		else
			current_a->target = find_biggest(vars->stack_b);
		current_a = current_a->next;
	}
}

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
	t_node *current;
	int i;
	int half;
	

	if(!*head)
		return ;
	current = *head;
	i = 0;
	half = list_size(*head) / 2;
	while(current)
	{
		current->index = i++;
		if (i <= half)
			(*head)->above_median = 1;
		else
			(*head)->above_median = 0;
		current = current->next;
	}
}

void	cost_analysis_a(t_vars *vars)
{
	int len_a;
	int len_b;
	t_node *current_a;

	len_a = list_size(vars->stack_a);
	len_b = list_size(vars->stack_b);
	current_a = vars->stack_a;
	while(current_a)
	{
		current_a->push_cost = current_a->index;
		if(!(current_a->above_median))
			current_a->push_cost = len_a - current_a->index;
		if(current_a->target->above_median)
			current_a->push_cost += current_a->target->index;
		else
			current_a->push_cost += len_b - current_a->target->index;
		current_a = current_a->next;
	}
}
