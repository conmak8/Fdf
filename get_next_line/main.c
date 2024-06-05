#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	// fd = STDIN_FILENO;

	line = get_next_line(fd);
	while (line)
	{
		printf("[%s]", line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return EXIT_SUCCESS;
}
