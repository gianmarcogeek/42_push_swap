/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:14:17 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:51:17 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | appends the NUL-terminateed string src to the end of dst.
 * 				   It will append at most size (strlen of dst - 1 byte),
 * 				   NUL-terminating the result */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	if (destsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (destsize <= ft_strlen(dst))
		return (destsize + ft_strlen(src));
	while (src[j] && i + 1 < destsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
