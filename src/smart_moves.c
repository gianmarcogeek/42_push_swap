/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:02:46 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/06/04 20:56:13 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_up(t_node **head, t_node *to_top, char stack)
{
	while(to_top != *head)
	{
		if(to_top->above_median)
			rotate(head, stack, 1);
		else
			rrotate(head, stack, 1);
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
	move_up(&vars->stack_a, cheapest, 'a');
	move_up(&vars->stack_b, cheapest->target, 'b');
	push(&vars->stack_a, &vars->stack_b, 'b', 1);
}

void	move_b_to_a(t_vars *vars)
{
	move_up(&vars->stack_a, vars->stack_b->target, 'a');
	push(&vars->stack_a, &vars->stack_b, 'a', 1);
}