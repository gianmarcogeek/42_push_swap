/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:22:55 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:35:46 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from ctype.h | converts char to uppercase */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
