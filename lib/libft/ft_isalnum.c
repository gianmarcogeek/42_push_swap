/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:34:14 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 19:48:31 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from ctype.h | checks for an alphanumeric character */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
