/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:55:32 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/20 19:37:15 by gpuscedd         ###   ########.fr       */
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

static void	push_swap(t_vars *vars)
{
	while(vars->n_args-- > 3)
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	tiny_sort(vars);
	while(vars->stack_b)
	{
		set_index(vars);
		set_cost(vars);
		
	}
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