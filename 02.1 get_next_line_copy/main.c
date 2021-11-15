#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
int main(void)
{
    int 	fd[3];
	char	*s;
	// int		num_string;
	// int		num_files;
	// int		i;

	//sleep(1);
	// i = 0;
	// num_files = 41;
	// num_string = 1;
    fd[0] = open("41_with_nl", O_RDONLY);
	fd[1] = open("42_with_nl", O_RDONLY);
	fd[2] = open("43_with_nl", O_RDONLY);
	s = get_next_line(fd[0]);
	printf("string 1 41_with_nl: %s", s);
	s = get_next_line(fd[1]);
	printf("string 1 42_with_nl: %s", s);
	s = get_next_line(fd[2]);
	printf("string 1 43_with_nl: %s", s);
	s = get_next_line(fd[0]);
	printf("string 2 41_with_nl: %s", s);
	s = get_next_line(fd[1]);
	printf("string 2 42_with_nl: %s", s);
	s = get_next_line(fd[2]);
	printf("string 2 43_with_nl: %s", s);
	s = get_next_line(fd[0]);
	printf("string 3 41_with_nl: %s", s);
	s = get_next_line(fd[1]);
	printf("string 3 42_with_nl: %s", s);
	s = get_next_line(fd[2]);
	printf("string 3 43_with_nl: %s", s);
	
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
