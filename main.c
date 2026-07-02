#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return (1);
		}
	}
	else
	{
		printf("--- Reading from Standard Input (Type something and press Enter) ---\n");
		fd = 0;
	}
	printf("--- Start Reading ---\n");
	while ((line = get_next_line(-1)) != NULL)
	{
		printf("Line [%02d]: |%s|", count++, line);
		free(line);
	}
	printf("\n--- End of Reading ---\n");
	if (fd != 0)
		close(fd);
	return (0);
}

/**
cc -Wall -Wextra -Werror
	-D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out test.txt
**/
