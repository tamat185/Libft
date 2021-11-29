/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:52:14 by ecosting          #+#    #+#             */
/*   Updated: 2021/11/03 14:52:14 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdlib.h>
// #include "../01. libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 2];
	char		*line;
	int			byte_was_read;
	char		*pointer_to_n;
	static char	*remainder;
	char		*tmp;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || read(fd, NULL, 0))
		return (NULL);
	pointer_to_n = make_line_from_remainder(&remainder, &line);
	while (((!pointer_to_n) && (byte_was_read = read(fd, buffer, BUFFER_SIZE))))
	{
		buffer[byte_was_read] = '\0';
		if ((pointer_to_n = ft_strchr(buffer, '\n')))
		{
			*pointer_to_n = '\0';
			remainder = strdup(pointer_to_n + 1);
			*pointer_to_n = '\n';
			*(pointer_to_n + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	if ((pointer_to_n == NULL) && (byte_was_read == 0)
		&& (ft_strlen(line) == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
