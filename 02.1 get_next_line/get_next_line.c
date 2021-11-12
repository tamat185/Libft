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
//#include <fcntl.h>
//#include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include "../01. libft/libft.h"
#include "get_next_line.h"

char *get_next_line(int fd)
{
    char        buffer[BUFFER_SIZE + 1];
    char        *line;
    int         byte_was_read;
    char        *pointer_to_n;
    static char *remainder;
	char		*tmp;

    //remainder = NULL;
	pointer_to_n = make_line_from_remainder(&remainder, &line);
    while (((!pointer_to_n) && (byte_was_read = read(fd, buffer, BUFFER_SIZE))))
    {
        buffer[byte_was_read] = '\0';
        if ((pointer_to_n = ft_strchr(buffer, '\n')))
        {
            *pointer_to_n = '\0';
            remainder = strdup(pointer_to_n + 1);
        }
		tmp = line;
        line = ft_strjoin(line, buffer);
		free(tmp);
    }
    return (line);
}

// int main(void)
// {
//     int fd;

//     fd = open("text.txt", O_RDONLY);
//     printf("%s\n\n", get_next_line(fd));
//     printf("%s\n\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     return 0;
// }