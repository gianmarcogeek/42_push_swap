/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:36:18 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:50:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | fills the first n bytes of the memory area pointed to by s
 *				   whit the constant byte c. */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n-- > 0)
		*(ptr++) = (unsigned char) c;
	return (s);
}
