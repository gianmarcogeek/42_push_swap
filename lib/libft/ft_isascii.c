/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:08:17 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:49:30 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from ctype.h | checks whether c is 7-bit unsigned char value 
 *				  that fits into the ASCII character set. */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
