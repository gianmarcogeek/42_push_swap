/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:30:24 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/04/20 23:09:15 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//funzione principale, inizializza il buffer statico nella stack
//inizializza line che sarà la stringa ritornata
//con ft_strcat_gnl, essenzialmente copia finchè non trova una new line
//e in caso ci sia salva il resto in buffer per la prossima chiamata
//se line e *line esistono ritorna line
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			chars_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_read = 1;
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (!*buffer)
			chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
			break ;
		line = line_realloc(line);
		ft_strcat_gnl(line, buffer);
	}
	if (line && *line)
		return (line);
	return (free(line), NULL);
}

//prende un area di memoria
//somma la dimensione della vecchia aria con buffer_size + 1
//rialloca con la nuova dimensione e libera la vecchia
char	*line_realloc(char *old_line)
{
	char	*new_line;

	new_line = ft_calloc(ft_strlen(old_line) + BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	if (old_line)
		ft_strcat(new_line, old_line);
	return (free(old_line), new_line);
}
