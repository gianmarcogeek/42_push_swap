/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:55:32 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/29 17:52:51 by gpuscedd         ###   ########.fr       */
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
		rotate(&vars->stack_a, 'a', 1);
	else if (vars->stack_a->next == biggest)
		rrotate(&vars->stack_a, 'a', 1);
	sort_two(vars);
}

void	reload_meta(t_vars *vars)
{
	set_index(vars->stack_a);
	set_index(vars->stack_b);
	set_target_in_a(vars);
	cost_analysis_a(vars);
}

void	push_swap(t_vars *vars)
{
	int size_a;

	size_a = list_size(vars->stack_a);
	if(size_a-- > 3 && check_sorting(vars->stack_a))
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	if(size_a-- > 3 && check_sorting(vars->stack_a))
		push(&vars->stack_a, &vars->stack_b, 'b', 1);
	while(size_a-- > 3 && check_sorting(vars->stack_a))
	{
		reload_meta(vars);
		//move_a_to_b()
	}
	tiny_sort(vars);
	while(vars->stack_b)
	{
		//relaod_meta_b???
		//move_b_to_a
	}
	//set_index_a
	//ensure_min_is_on_top
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