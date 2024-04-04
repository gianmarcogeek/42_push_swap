/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/04 19:22:26 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list_a;
	char	**args_str;
	int		n_args;

	list_a = NULL;
	args_str = NULL;
	n_args = 0;
	if (argc == 2)
	{
		args_str = ft_split(argv[1], ' ');
		n_args = ft_splitlen(args_str);
		check_and_init(&list_a, args_str, n_args);
	}
	else if (argc > 2)
		check_and_init(&list_a, argv + 1, argc - 1);
	check_for_dup(list_a);
	
	if (list_a != NULL)
	{
		t_node *current = list_a;
		while(current)
		{
			ft_printf("value: %d\n", current->data);
			current = current->next;
		}
	}
}
