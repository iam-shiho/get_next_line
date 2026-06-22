#include "get_next_line.h"

char	*read_buf(int fd, char *buf)
{
	ssize_t	tmp;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	if (!buf)
		return (NULL);
	tmp = read(fd, buf, BUFFER_SIZE);
	printf("%zd\n", tmp);
	if (tmp > 0)
	{
		buf[tmp] = '\0';
	}
	return (buf);
}

int	main(void)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./a.txt", O_RDONLY);
	printf("%s", read_buf(fd, buf));
	close(fd);
}
