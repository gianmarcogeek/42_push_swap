/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:36:30 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/03/20 10:53:49 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/libft.h"

//input_check
void	input_check(int argc, char *argv[]);
void	check_integers(int argc, char *argv[]);
void	check_int_size(int argc, char *argv[]);
void	check_doubles(int argc, char *argv[]);
void	print_error_and_exit(int error_code);

#endif