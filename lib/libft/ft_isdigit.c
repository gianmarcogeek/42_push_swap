/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:28:43 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:49:38 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from ctype.h | checks for an digit character (0 through 9) */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
