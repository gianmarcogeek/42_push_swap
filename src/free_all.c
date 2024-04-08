/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 18:49:33 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_node **head_a, t_node **head_b, char **matrix, int argc)
{
	if (argc == 2)
		free_matrix(matrix);
	if (*head_a)
		free_stack(head_a);
	if (*head_b)
		free_stack(head_b);	
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

