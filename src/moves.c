/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:39 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/05 14:42:48 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **lst, char stack, bool print)
{
	t_node *tmp;

	if(!lst || !(*lst) || !((*lst)->next))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if(print)
		ft_printf("s%c\n", stack);
}

void	rotate(t_node **lst, char stack, bool print)
{
	t_node *last;
	t_node *tmp;

	last = find_last_node(*lst);
	tmp = *lst;

	*lst = (*lst)->next;
	last->next = tmp;
	tmp->next = NULL;
	if(print)
		ft_printf("r%c\n", stack);
}

void	rrotate(t_node **lst, char stack, bool print)
{
	t_node *last;
	t_node *new_last;

	new_last = *lst;
	last = find_last_node(*lst);
	while(new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if(print)
		ft_printf("rr%c\n", stack);
}

void	push(t_node **stack_a, t_node **stack_b, char stack, bool print)
{
	t_node *tmp;
	
	if (stack == 'b' && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	else if (stack == 'a' && *stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	else
		return ;
	if (print)
		ft_printf("p%c\n", stack);
}

void	do_both(t_node **stack_a, t_node **stack_b, char *move)
{
	
	if(ft_strncmp(move, "swap", 4) == 0)
	{
		swap(stack_a, 'a', 0);
		swap(stack_b, 'b', 0);
		ft_printf("ss\n");
	}
	else if(ft_strncmp(move, "rotate", 6) == 0)
	{
		rotate(stack_a, 'a', 0);
		rotate(stack_b, 'b', 0);
		ft_printf("rr\n");
	}
	else if(ft_strncmp(move, "rrotate", 7) == 0)
	{
		rrotate(stack_a, 'a', 0);
		rrotate(stack_b, 'b', 0);
		ft_printf("rrr\n");
	}
}