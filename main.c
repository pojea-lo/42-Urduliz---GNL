#include "get_next_line.h"

int	main(void)
{
	int			fd;
//	int			j;
	char		*line;

//	j = 0;
//	fd = open ("julia.fdf", O_RDWR);
//	fd = open ("mars.fdf", O_RDWR);
	fd = open ("42.fdf", O_RDWR);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free (line);
//		printf("---------%d-----------\n", j);
		line = get_next_line(fd);
		printf ("%s", line);
//		j++;
	}
	free (line);
	system ("leaks a.out");
	close(fd);
	return (0);
}

/*
Compilación:

cc -Wall -Werror -Wextra -D BUFFER_SIZE=1000 get_next_line.c get_next_line.h get_next_line_utils.c main.c && ./a.out | cat -e

*/
