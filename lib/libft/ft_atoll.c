/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/05/11 14:19:23 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from stdlib.h | convert a string to an integer. */
#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	res;

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
