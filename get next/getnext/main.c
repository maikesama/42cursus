#include "get_next_line.h"

int		main()
{
	char *line[1];
	int fd;

	fd = open("test.txt", O_RDONLY);
	/*if (get_next_line(fd, line) < 0)
	{
		printf("ERROR\n");
		return 0;
	}
	else
		return 0;*/
	//while (get_next_line(fd, line))
		get_next_line(fd, line);
	return (0);
}