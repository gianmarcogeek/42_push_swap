/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:46:16 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/04 13:16:27 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_for_dup(t_node *head)
{
	t_node *current;
	t_node *compare;

	current = head;
	while(current)
	{
		compare = current->next;
		while(compare)
		{
			if(current->data == compare->data)
				ft_error("Each number cannot occur twice.");
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}