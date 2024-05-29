/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:55:32 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/29 19:49:39 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_vars *vars)
{
	if(vars->stack_a && vars->stack_a->next)
		if (vars->stack_a->data > vars->stack_a->next->data)
			swap(&vars->stack_a, 'a', 1);
}

static void tiny_sort(t_vars *vars)
{
	t_node *biggest = find_biggest(vars->stack_a);
	if (vars->stack_a == biggest)
		rrotate(&vars->stack_a, 'a', 1);
	else if (vars->stack_a->next == biggest)
		rotate(&vars->stack_a, 'a', 1);
	sort_two(vars);
}

static void	push_swap(t_vars *vars)
{
	int size_a;

	size_a = list_size(vars->stack_a);
	if(size_a-- > 3 && !check_sorting(vars->stack_a))
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	if(size_a-- > 3 && !check_sorting(vars->stack_a))
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	while(size_a-- > 3 && !check_sorting(vars->stack_a))
	{
		reload_meta_a(vars);
		move_a_to_b(vars);
	}
	tiny_sort(vars);
	while(vars->stack_b)
	{
		reload_meta_b(vars);
		move_b_to_a(vars);
	}
	set_index(&vars->stack_a);
	move_up(&vars->stack_a, find_smallest(vars->stack_a), 'a');
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