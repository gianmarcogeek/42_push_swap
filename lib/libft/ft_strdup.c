/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:18:53 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:51:05 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | returns a pointer to a new string which is
 * 				   a duplicate of the string s. */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	i;

	i = 0;
	dup_s = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup_s)
		return (NULL);
	while (s[i])
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[ft_strlen(s)] = '\0';
	return (dup_s);
}
