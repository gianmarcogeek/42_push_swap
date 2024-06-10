/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:18 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:50:29 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | Compares the first num bytes of the block of memory
* 				   pointed by ptr1 to the first num bytes pointed by ptr2,
*				   returning zero if they all match or a value different
*				   from zero representing which is greater if they do not. */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)ptr1;
	b2 = (unsigned char *)ptr2;
	while (n-- > 0)
	{
		if (*b1 == *b2)
		{
			b1++;
			b2++;
		}
		else
			return (*b1 - *b2);
	}
	return (0);
}
