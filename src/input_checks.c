/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:41:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 17:32:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_and_init(t_node **head, char **args, int n_args)
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
				insert_in_stack(head, number);
			else
				ft_error(ERROR_SIZE);
		}
		else
			ft_error(ERROR_INVALID);
		i++;
	}
}

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

bool	check_for_dup(t_node *head)
{
	t_node	*current;
	t_node	*compare;

	current = head;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->data == compare->data)
				ft_error(ERROR_DOUBLE);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}
