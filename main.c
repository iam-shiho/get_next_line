#include "get_next_line.h"

// char	*read_buf(int fd, char *buf)
// {
// 	ssize_t	tmp;

// 	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
// 	if (!buf)
// 		return (NULL);
// 	tmp = read(fd, buf, BUFFER_SIZE);
// 	printf("%zd\n", tmp);
// 	if (tmp > 0)
// 	{
// 		buf[tmp] = '\0';
// 	}
// 	return (buf);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	buf = NULL;
// 	fd = open("./a.txt", O_RDONLY);
// 	printf("%s", read_buf(fd, buf));
// 	close(fd);
// }
char	*ft_strdup(char *s)
{
	size_t			len;
	char			*dest;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	//free(s);
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\0') //改行があるのか気にする
		++size;
	return (size);
}

void	ft_strlcpy(char *res, char *stuck, size_t size)
{
	size_t	i;

	i = 0;
	while (stuck[i] != '\0' && i < size -1)
	{
		res[i] = stuck[i];
		++i;
	}
	res[i] = '\0';
	free(stuck);
}

int main()
{
	char *str1;
	char *str2;
	char *str3;
	size_t i;

	str3 = malloc(8);
	str1 = ft_strdup("Hello");
	str2 = ft_strdup("42");
	ft_strlcpy(str3, str1, 6);
	i = ft_strlen(str3);
	ft_strlcpy(&str3[i], str2, 3);
	write(1,str3,10);
}
