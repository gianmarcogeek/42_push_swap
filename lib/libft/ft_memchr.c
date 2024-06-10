/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:33:58 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:50:25 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | scans the initial n bytes of the memory area pointed
 *				   by s for the first instance of c */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sp;

	sp = (const unsigned char *) s;
	while (n-- > 0)
	{
		if (*sp == (const unsigned char) c)
			return ((void *)sp);
		sp++;
	}
	return (NULL);
}
