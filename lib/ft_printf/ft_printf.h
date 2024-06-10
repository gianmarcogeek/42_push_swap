/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/06/05 11:56:49 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifdef __APPLE__
#  define NIL_STRING "0x0"
# endif
# ifdef __unix__
#  define NIL_STRING "(nil)"
# endif

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long n, int fd);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_putptr(unsigned long long address);
int		ft_printf(const char *str, ...);

#endif
