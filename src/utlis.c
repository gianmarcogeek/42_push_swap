/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:40:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 17:37:43 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *message)
{
	ft_printf("\n\e[41m\e[1mError!\e[0m %s\n\n", message);
	exit(1);
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	display_stacks(t_node *head_a, t_node *head_b)
{
	t_node	*current;
	
	current = NULL;
	ft_printf("\nSTACK A:\n");
	if (head_a != NULL)
	{
		current = head_a;
		while(current)
		{
			ft_printf("[%d] ", current->data);
			current = current->next;
		}
	}
	ft_printf("\n");
	ft_printf("STACK B:\n");
	if (head_b != NULL)
	{
		current = head_b;
		while(current)
		{
			ft_printf("[%d] ", current->data);
			current = current->next;
		}
	}
}
