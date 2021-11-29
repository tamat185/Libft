#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s1)
		return (NULL);
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_calloc(size_t count, size_t size, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if ((!str1 || !str2) || (!str1 && !str2))
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

/*
char	*make_line_from_remainder(char **remainder, char **line)
{
	char	*pointer_to_n;

	pointer_to_n = NULL;
	if (*remainder)
	{
		pointer_to_n = ft_strchr(*remainder, '\n');
		if (pointer_to_n)
		{
			*pointer_to_n = '\0';
			if (pointer_to_n == remainder[0])
				*line = ft_calloc(1, 1, '\n');
			else
			{
				*line = ft_strjoin(*remainder, "\n");
				ft_strcpy(*remainder, pointer_to_n + 1);
			}
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1, '\0');
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*pointer_to_n;
	char		*tmp;
	int			byte_was_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	line = make_line_from_remainder(&remainder, &line);
	pointer_to_n = NULL;
	byte_was_read = read(fd, buffer, BUFFER_SIZE);
	while (!pointer_to_n && byte_was_read)
	{
		buffer[byte_was_read] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			pointer_to_n = ft_strchr(buffer, '\n');
			if (pointer_to_n && (BUFFER_SIZE != 1))
			{
				remainder = ft_strdup(pointer_to_n + 1);
				*pointer_to_n = '\n';
				*(pointer_to_n + 1) = '\0';
			}
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (!pointer_to_n)
			byte_was_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (pointer_to_n == NULL && byte_was_read == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
*/

char	*make_line_from_remainder(char **remainder, char **line)
{
	char	*pointer_to_n;

	pointer_to_n = NULL;
	if (*remainder)
	{
		if (ft_strchr(*remainder, '\n'))
		{
			pointer_to_n = ft_strchr(*remainder, '\n');
			*pointer_to_n = '\0';
			*line = ft_strjoin(*remainder, "\n");
			ft_strcpy(*remainder, (pointer_to_n + 1));
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1, '\0');
	return (pointer_to_n);
}


/*char	*get_next_line(fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	char		*pointer_to_n;
	char		*tmp;
	static char	*remainder;
	size_t		byte_was_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	pointer_to_n = make_line_from_remainder(&remainder, &line);
	if (!pointer_to_n)
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
	while (!pointer_to_n && byte_was_read)
	{
		buffer[byte_was_read] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			pointer_to_n = ft_strchr(buffer, '\n');
			*pointer_to_n = '\0';
			remainder = ft_strdup(pointer_to_n + 1);
			*pointer_to_n = '\n';
			*(pointer_to_n + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (!pointer_to_n)
			byte_was_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (pointer_to_n == NULL && byte_was_read == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
*/

char	*get_next_line(fd)
{
	char		*pointer_to_n;
	static char	*remainder;
	char		*line;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	size_t		byte_was_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	pointer_to_n = make_line_from_remainder(&remainder, &line);
	if (!pointer_to_n)
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
	while (!pointer_to_n && byte_was_read)
	{
		buffer[byte_was_read] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			pointer_to_n = ft_strchr(buffer, '\n');
			*pointer_to_n = '\0';
			remainder = ft_strdup(pointer_to_n + 1);
			*pointer_to_n = '\n';
			*(pointer_to_n + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (!pointer_to_n)
			byte_was_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (pointer_to_n == NULL && byte_was_read == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}