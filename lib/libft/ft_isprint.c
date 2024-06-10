/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:18:56 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:35:32 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from ctype.h | checks for any printable character including space. */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
