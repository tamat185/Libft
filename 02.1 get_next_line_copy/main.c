#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main(void)
{
    int fd;
	char	*s;

    fd = open("multiple_line_no_nl", O_RDONLY);
	//fd = open("text.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	
	// s = get_next_line(fd);
	// printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	// 	s = get_next_line(fd);
	// while (s)
	// {
    // 	printf("%s", s);
	// 	s = get_next_line(fd);
	// }
	//printf("%s\n\n", get_next_line(fd));
    //printf("%s\n", get_next_line(fd));
    return 0;
}