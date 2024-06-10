/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:52:54 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:39:44 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		tot_len;
	char		*joined;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((tot_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcpy(joined + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	joined[tot_len] = '\0';
	return (joined);
}
