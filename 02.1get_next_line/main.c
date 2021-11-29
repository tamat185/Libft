#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("empty", O_RDONLY);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
}
