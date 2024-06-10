/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:31:13 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/03/06 17:39:36 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//uno strcat modificato, se trova una newline interrompe
//se la new line non è l'ultimo elemento del buffer salva
//il resto all'inizio del buffer
void	ft_strcat_gnl(char *dst, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(dst);
	while (src[j])
	{
		dst[i + j] = src[j];
		src[j] = '\0';
		j++;
		if (dst[i + j - 1] == '\n')
			break ;
	}
	if (src[j])
		ft_strcat(src, src + j);
}
