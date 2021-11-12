#include "get_next_line.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char    *make_line_from_remainder(char **remainder, char **line)
{
    char    *pointer_to_n;
	char	*c;

    c = "\n";
	pointer_to_n = NULL;
    if (*remainder)
    {
        if ((pointer_to_n = ft_strchr(*remainder, '\n')))
        {
            *pointer_to_n = '\0';
			if (pointer_to_n == remainder[0])
				*line = ft_calloc(1, 1, '\n');
			else
            	//*line = ft_strdup(*remainder);
				*line = ft_strjoin(*remainder, c);
            ft_strcpy(*remainder, pointer_to_n + 1);
        }
        else
		{
            *line = ft_strdup(*remainder);
			*remainder = NULL;
		}
    }
    else
        *line = ft_calloc(1, 1, '\0');
    return (pointer_to_n);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	size_t	len_strjoin;

	i = 0;
	j = 0;
	if ((!s1 || !s2) || (!s1 && !s2))
		return (NULL);
	len_strjoin = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * len_strjoin);
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

void	*ft_calloc(size_t count, size_t size, char c)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = malloc(count * size);
	if (!s1)
		return (NULL);
	while (i < count * size)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
