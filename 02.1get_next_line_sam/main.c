#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
	line = get_next_line(fd);
	printf("line = %s", line);
}
