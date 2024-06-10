/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:27:33 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/22 23:36:40 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | returns a pointer to the first occurrence of the caracter c
 * 		  		   in the string s. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s && *s)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
