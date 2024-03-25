/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:41:40 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/03/20 18:13:30 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	input_check(int argc, char *argv[])
{
	check_integers(argc, argv);
	check_int_size(argc, argv); 
	//check_doubles(argc, argv); //capire quando e come fare questo controllo, verifica che non ci siano doppioni
}
void	check_integers(int argc, char *argv[])
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			print_error_and_exit(1);
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				print_error_and_exit(1);
			j++;
		}
		i++;
	}
}
void	check_int_size(int argc, char *argv[])
{
	long	num;
	int	i;

	i = 1;
	while(i < argc)
	{
		num = ft_atoll(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			print_error_and_exit(2);
		i++;
	}
}
// void	check_doubles(int argc, char *argv[])
// {
// 	ok ha senso una volta messi i dati nella lista
// 	print_error_and_exit(3);
// }

void	print_error_and_exit(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd("\e[91mError!\e[0m Gli argomenti devono essere numeri interi decimali\n", 2);
		exit(error_code);
	}
	if (error_code == 2)
	{
		ft_putstr_fd("\e[91mError!\e[0m I numeri sono troppo grandi\n", 2);
		exit(error_code);
	}
	// if (error_code == 3)
	// 	exit(ft_putstr_fd("Error! Attento ai doppioni", 2), error_code);
}