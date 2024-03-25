/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:50:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/03/20 18:07:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		//argv = ft_split(argv[1], ' ');
		//aggiornare argc con il numero di argomenti
	}
	input_check(argc, argv);
	
	int i = 0;
	while(i < argc)
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
	//sorting
	return (0);
}