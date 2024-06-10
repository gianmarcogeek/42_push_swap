/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:47:20 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:34:41 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | returns a pointer to the last occurrence of the caracter c
 * 		   		   in the string s. */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len >= 0)
	{
		if (s[len] == (const char) c)
			return ((char *) s + len);
		len--;
	}
	return (NULL);
}
