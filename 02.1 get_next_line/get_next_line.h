#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	ft_strcpy(char *dst, char *src);
char    *make_line_from_remainder(char **remainder, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif 