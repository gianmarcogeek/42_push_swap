/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:20:48 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/03/14 17:30:16 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s)
	{
		while (*s)
		{
			len += ft_putchar_fd(*s, fd);
			s++;
		}
	}
	else
		len += ft_putstr_fd("(null)", 1);
	return (len);
}
