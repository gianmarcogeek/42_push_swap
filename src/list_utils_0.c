/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:06:43 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/07/30 22:43:28 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insert_in_stack(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = NULL;
	last = NULL;
	if (*head == NULL)
	{
		new_node = malloc(sizeof(t_node));
		init_meta(&new_node, value);
		*head = new_node;
	}
	else
	{
		last = find_last_node(*head);
		new_node = malloc(sizeof(t_node));
		init_meta(&new_node, value);
		last->next = new_node;
	}
}

t_node	*find_last_node(t_node *head)
{
	t_node	*current;

	current = head;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int	list_size(t_node *head)
{
	t_node	*current;
	size_t	i;

	current = head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_node	*find_biggest(t_node *head)
{
	t_node	*current;
	t_node	*biggest;

	current = head;
	biggest = head;
	while (current)
	{
		if (current->data > biggest->data)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_node	*find_smallest(t_node *head)
{
	t_node	*current;
	t_node	*smallest;

	current = head;
	smallest = head;
	while (current)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}
