/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:23:02 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:44:01 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(long nb)
{
	size_t	count;

	count = 1;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	digits;
	long	nbr;

	nbr = n;
	digits = digit_count(nbr);
	result = (char *)malloc((digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	digits--;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		result[digits] = (nbr % 10) + '0';
		nbr = nbr / 10;
		digits--;
	}
	if (nbr >= 0 && nbr <= 9)
		result[digits] = nbr + '0';
	return (result);
}
