/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:03:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/29 12:44:26 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_putchar_fd('%', 1);
	else if (format == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		len += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_format(args, *(++str));
			str++;
		}
		else
		{
			len += ft_putchar_fd(*str, 1);
			str++;
		}
	}
	va_end (args);
	return (len);
}
