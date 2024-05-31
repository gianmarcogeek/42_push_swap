/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:00:28 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/30 23:54:21 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node *find_cheapest(t_node *head)
{
	t_node *current;
	t_node *cheapest;
	
	current = head;
	cheapest = head;
	while(current)
	{
		if(current->push_cost < cheapest->push_cost)
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
	if (!(smallest_bigger->data > data))
		return (NULL);
	while(current)
	{
		if(current->data > data && current->data < smallest_bigger->data)
			smallest_bigger = current;
		current = current->next;
	}
	return(smallest_bigger);
}

t_node *find_closest_smaller(t_node *head, int data)
{
	t_node *current;
	t_node *closest_smaller;

	current = head;
	closest_smaller = find_smallest(head);
	if (!(closest_smaller->data < data))
		return (NULL);
	while(current)
	{
		if(current->data < data && current->data > closest_smaller->data)
			closest_smaller = current;
		current = current->next;
	}
	return(closest_smaller);
}

int	check_sorting(t_node *head)
{
	t_node *current;

	current = head;
	while(current->next)
	{
		if(current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}