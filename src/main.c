/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/06/09 13:47:36 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TO-DO
- capire meglio algoritmo e ottimizzare alcuni step
- norminette todos
- pushare libft e printf aggiornate nelle loro repo
*/

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars, argc, argv);
	check_and_push(&vars);
	if (!check_sorting(vars.stack_a))
		sort(&vars);
	free_all(&vars);
	return (0);
}
