/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:55:32 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/22 12:47:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_vars *vars)
{
		if (vars->stack_a->data > vars->stack_a->next->data)
			swap(&vars->stack_a, 'a', 1);
}

static void tiny_sort(t_vars *vars)
{
	t_node *biggest = find_biggest(vars->stack_a);
	if (vars->stack_a == biggest)
		rotate(&vars->stack_a, 'a', 1);
	else if (vars->stack_a->next == biggest)
		rrotate(&vars->stack_a, 'a', 1);
	sort_two(vars);
}

void	move_nodes(t_vars *vars)
{
	t_node *cheapest;

	cheapest = find_cheapest(vars->stack_b);
	if (cheapest->above_median && cheapest->target->above_median)
		do_both(&vars->stack_a, &vars->stack_b, "rotate");
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		do_both(&vars->stack_a, &vars->stack_b, "rrotate");
	push(&vars->stack_a, &vars->stack_b, 'a', 1);
}

static void	push_swap(t_vars *vars)
{
	while(vars->n_args-- > 3)
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	tiny_sort(vars);
	// while(vars->stack_b)
	// {
	// 	set_index(vars->stack_a);
	// 	set_index(vars->stack_b);
	// 	set_cost(vars);
	// 	move_nodes(vars);
	// }
}

void	sort(t_vars *vars)
{
		if (vars->n_args == 2)
			sort_two(vars);
		if (vars->n_args == 3)
			tiny_sort(vars);
		if (vars->n_args > 3)
			push_swap(vars);
}