/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:19:41 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/27 20:37:52 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr(long long nbr, int base_val, char *symbols)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len += ft_putchar_fd('-', 1);
	}
	if (nbr >= base_val)
		len += print_nbr((nbr / base_val), base_val, symbols);
	len += ft_putchar_fd(symbols[nbr % base_val], 1);
	return (len);
}

static int	double_char(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (symbols[i])
	{
		j = i + 1;
		while (symbols[j])
		{
			if (symbols[i] == symbols[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	base_val;
	int	len;

	base_val = 0;
	len = 0;
	while (base[base_val])
	{
		if (base[base_val] == '+' || base[base_val] == '-')
			return (0);
		++base_val;
	}
	if (base_val < 2)
		return (0);
	if (double_char(base))
		return (0);
	len += print_nbr(nbr, base_val, base);
	return (len);
}
