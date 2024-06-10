/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:05:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:48:26 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from stdlib.h | is used to dynamically allocate memory for an array
 *				   and initialize all its elements to zero. */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	out = malloc(count * size);
	if (out == NULL)
		return (out);
	ft_bzero(out, count * size);
	return (out);
}
