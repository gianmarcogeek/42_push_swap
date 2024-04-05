/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:39 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/05 05:12:28 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **lst, char stack, bool print)
{
	t_node *tmp;

	if(!lst || !((*lst)->next))
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
	
	if (stack == 'a')
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	if (stack == 'b')
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (print)
		ft_printf("p%c\n", stack);
}