/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:06:43 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/20 19:38:57 by gpuscedd         ###   ########.fr       */
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

t_node *find_cheaper(t_node *head)
{
	t_node *current;
	t_node *cheaper;
	
	current = head;
	cheaper = head;
	while(current)
	{
		if(current->push_cost > cheaper->push_cost)
			cheaper = current;
		current = current->next;
	}
	return(cheaper);
}

t_node *find_smallest_bigger(t_node *head, int data)
{
	t_node *current;
	t_node *smallest_bigger;

	current = head;
	smallest_bigger = find_bigger(head);
	while(current)
	{
		if(current->data > data && current->data < smallest_bigger->data)
			smallest_bigger = current;
		current = current_next;
	}
	return(smallest_bigger)
}
