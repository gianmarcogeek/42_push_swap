/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:39 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/22 02:10:58 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **head, char stack, int print)
{
	t_node *tmp;

	if(!head || !(*head) || !((*head)->next))
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if(print)
		ft_printf("s%c\n", stack);
}

void	rotate(t_node **head, char stack, int print)
{
	t_node *last;
	t_node *tmp;

	if(!head || !(*head))
		return ;
	last = find_last_node(*head);
	tmp = *head;

	*head = (*head)->next;
	last->next = tmp;
	tmp->next = NULL;
	if(print)
		ft_printf("r%c\n", stack);
}

void	rrotate(t_node **head, char stack, int print)
{
	t_node *last;
	t_node *new_last;

	if(!head || !(*head))
		return ;
	new_last = *head;
	last = find_last_node(*head);
	while(new_last->next)
		new_last = new_last->next;
	new_last->next = NULL;
	last->next = *head;
	*head = last;
	if(print)
		ft_printf("rr%c\n", stack);
}

void	push(t_node **head_a, t_node **head_b, char stack, int print)
{
	t_node *tmp;
	
	if (stack == 'b' && *head_a)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = *head_b;
		*head_b = tmp;
	}
	else if (stack == 'a' && *head_b)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = *head_a;
		*head_a = tmp;
	}
	else
		return ;
	if (print)
		ft_printf("p%c\n", stack);
}

void	do_both(t_node **head_a, t_node **head_b, char *move)
{
	
	if(ft_strncmp(move, "swap", 4) == 0)
	{
		swap(head_a, 'a', 0);
		swap(head_b, 'b', 0);
		ft_printf("ss\n");
	}
	else if(ft_strncmp(move, "rotate", 6) == 0)
	{
		rotate(head_a, 'a', 0);
		rotate(head_b, 'b', 0);
		ft_printf("rr\n");
	}
	else if(ft_strncmp(move, "rrotate", 7) == 0)
	{
		rrotate(head_a, 'a', 0);
		rrotate(head_b, 'b', 0);
		ft_printf("rrr\n");
	}
}