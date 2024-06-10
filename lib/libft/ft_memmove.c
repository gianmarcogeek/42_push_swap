/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:49:46 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:50:37 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | copies n bytes from memory area src to memery area dest.
 * 		   		   The memory area must not overlap. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n-- > 0)
			*(--d) = *(--s);
	}
	return (dst);
}
