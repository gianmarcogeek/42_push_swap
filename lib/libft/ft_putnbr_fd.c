/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:25:34 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/25 19:00:29 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long n, int fd)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		len += ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		len += ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			len += ft_putnbr_fd(n / 10, fd);
		len += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (len);
}
