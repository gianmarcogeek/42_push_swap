/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/05 05:21:13 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node *current;
	char	**args_str;
	int		n_args;

	stack_a = NULL;
	stack_b = NULL;
	current = NULL;
	args_str = NULL;
	n_args = 0;
	if (argc == 2)
	{
		args_str = ft_split(argv[1], ' ');
		n_args = ft_splitlen(args_str);
		check_and_init(&stack_a, args_str, n_args);
	}
	else if (argc > 2)
		check_and_init(&stack_a, argv + 1, argc - 1);
	check_for_dup(stack_a);
	
	if (stack_a != NULL)
	{
		current = stack_a;
		while(current)
		{
			ft_printf("value: %d\n", current->data);
			current = current->next;
		}
	}
	
	ft_printf("\n");
	
	push(&stack_a, &stack_b, 'a', 1);
	
	ft_printf("\n");
	
	if (stack_a != NULL)
	{
		current = stack_a;
		while(current)
		{
			ft_printf("value: %d\n", current->data);
			current = current->next;
		}
	}
}

