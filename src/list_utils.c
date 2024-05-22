/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:06:43 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/22 12:45:19 by gpuscedd         ###   ########.fr       */
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
		new_node->data = value;
		new_node->next = NULL;
		new_node->index = 0;
		new_node->push_cost = 0;
		new_node->target = NULL;
		*head = new_node;
	}
	else
	{
		last = find_last_node(*head);
		new_node = malloc(sizeof(t_node));
		new_node->data = value;
		new_node->next = NULL;
		last->next = new_node;
	}
}

t_node	*find_last_node(t_node *head)
{
	t_node	*current;

	current = head;
	if (!head)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int	list_size(t_node *head)
{
	t_node *current;
	size_t i;

	current = head;
	i = 0;
	while(current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_node *find_biggest(t_node *head)
{
	t_node *current;
	t_node *biggest;
	
	current = head;
	biggest = head;
	while(current)
	{
		if(current->data > biggest->data)
			biggest = current;
		current = current->next;
	}
	return(biggest);
}

t_node *find_smallest(t_node *head)
{
	t_node *current;
	t_node *smallest;
	
	current = head;
	smallest = head;
	while(current)
	{
		if(current->data > smallest->data)
			smallest = current;
		current = current->next;
	}
	return(smallest);
}

t_node *find_cheapest(t_node *head)
{
	t_node *current;
	t_node *cheapest;
	
	current = head;
	cheapest = head;
	while(current)
	{
		if(current->push_cost > cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return(cheapest);
}

t_node *find_smallest_bigger(t_node *head, int data)
{
	t_node *current;
	t_node *smallest_bigger;

	current = head;
	smallest_bigger = find_biggest(head);
	while(current)
	{
		if(current->data > data && current->data < smallest_bigger->data)
			smallest_bigger = current;
		current = current->next;
	}
	return(smallest_bigger);
}
