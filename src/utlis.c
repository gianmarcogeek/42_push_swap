/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 10:59:26 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_splitlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	display_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;
	
	current = NULL;
	ft_printf("\nSTACK A:\n");
	if (stack_a != NULL)
	{
		current = stack_a;
		while(current)
		{
			ft_printf("\n[%d]\n", current->data);
			current = current->next;
		}
	}
	ft_printf("\nSTACK B:\n");
	if (stack_b != NULL)
	{
		current = stack_b;
		while(current)
		{
			ft_printf("\n[%d]\n", current->data);
			current = current->next;
		}
	}
}
