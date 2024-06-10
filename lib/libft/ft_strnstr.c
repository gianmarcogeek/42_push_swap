/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:51:49 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:34:56 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | locates the first occurence of the null-terminated string
 * 				   string "little" in the null-terminated string "big" */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	while (haystack[0] && len != 0)
	{
		i = 0;
		while (haystack[i] && haystack[i] == needle[i] && len - i > 0)
		{
			if (ft_strlen(needle) == i + 1)
				return ((char *)haystack);
			i++;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
