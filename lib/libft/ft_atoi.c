/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 20:45:50 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from stdlib.h | convert a string to an integer. */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	if (!str || !*str)
		return (0);
	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res += *str - 48;
		str++;
	}
	return (res * sign);
}
