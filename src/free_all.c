/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/06/04 22:49:56 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_vars *vars)
{
	if (vars->og_argc == 2 && vars->args_str)
		free_matrix(vars->args_str);
	if (vars->stack_a)
		free_stack(&vars->stack_a);
	if (vars->stack_b)
		free_stack(&vars->stack_b);	
}
void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while(matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
}

void	free_stack(t_node **head)
{
	t_node *temp;

	while(*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

