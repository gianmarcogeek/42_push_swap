/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:41:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/05 03:24:02 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_and_init(t_node **list, char **args, int n_args)
{
	int		i;
	long	number;

	i = 0;
	while (i < n_args)
	{
		if (check_number(args[i]))
		{
			number = ft_atoll(args[i]);
			if (number >= INT_MIN && number <= INT_MAX)
				insert_in_stack(list, number);
			else
				ft_error(ERROR_SIZE);
		}
		else
			ft_error(ERROR_INVALID);
		i++;
	}
}

/**********************/

bool	check_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if(arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return(1);
}

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
