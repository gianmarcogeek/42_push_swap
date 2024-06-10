/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:24 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/19 21:33:08 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* from string.h | fills the first n bytes of the memory area pointed to by s
*	  			   whit zero (bytes containing '\0'). */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
