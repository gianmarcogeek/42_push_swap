/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/08 18:40:28 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args_str;
	size_t		n_args;

	stack_a = NULL;
	stack_b = NULL;
	args_str = NULL;
	n_args = 0;
	if (argc == 2)
	{
		args_str = ft_split(argv[1], ' ');
		n_args = matrix_len(args_str);
	}
	else if (argc > 2)
	{
		args_str = argv + 1;
		n_args = argc - 1;
	}
	check_and_init(&stack_a, args_str, n_args);
	check_for_dup(stack_a);
	
	display_stacks(stack_a, stack_b);

	//sort(&stack_a, &stack_b);
	push(&stack_a, &stack_b, 'b', 1);
	
	display_stacks(stack_a, stack_b);
	
	free_all(&stack_a, &stack_b, args_str, argc);

	return (0);
}

