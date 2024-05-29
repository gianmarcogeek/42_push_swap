/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/29 18:55:59 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_node *head)
{
	t_node *current;
	int i;
	int half;
	

	if(!head)
		return ;
	current = head;
	i = 0;
	half = list_size(head) / 2;
	while(current)
	{
		current->index = i++;
		if (i <= half)
			head->above_median = 1;
		else
			head->above_median = 0;
		current = current->next;
	}
}
void	set_target_in_a(t_vars *vars)
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

void	set_target_in_b(t_vars *vars)
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

void	move_up(t_node *head, t_node *to_top, char stack)
{
	while(to_top != head)
	{
		if(to_top->above_median)
			rotate(&head, stack, 1);
		else
			rrotate(&head, stack, 1);
	}
}

void	move_a_to_b(t_vars *vars)
{
	t_node *cheapest;

	cheapest = find_cheapest(vars->stack_a);
	if(cheapest->above_median && cheapest->target->above_median)
		do_both(&vars->stack_a, &vars->stack_b, "rotate");
	if(!(cheapest->above_median) && !(cheapest->target->above_median))
		do_both(&vars->stack_a, &vars->stack_b, "rrotate");
	move_up(vars->stack_a, cheapest, 'a');
	move_up(vars->stack_b, cheapest->target, 'a');
	push(&vars->stack_a, &vars->stack_b, 'b', 1);
}

void	move_b_to_a(t_vars *vars)
{
	move_up(vars->stack_a, vars->stack_b->target, 'a');
	push(&vars->stack_a, &vars->stack_b, 'a', 1);
}
