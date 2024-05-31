/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/30 23:59:06 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;
	init_vars(&vars, argc, argv);
	check_and_push(&vars);
	
	// display_stacks(vars.stack_a, vars.stack_b);
	
	if(!check_sorting(vars.stack_a))
	{
		// ft_printf("\nsorting...\n");
		sort(&vars);
		// display_stacks(vars.stack_a, vars.stack_b);
	}
	
	free_all(&vars);
	return (0);
 }
