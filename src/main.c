/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/20 17:28:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars, argc, argv);
	
	check_and_push(&vars);

	display_stacks(vars.stack_a, vars.stack_b);

	sort(&vars);
	
	display_stacks(vars.stack_a, vars.stack_b);
	
	free_all(&vars);

	return (0);
}

