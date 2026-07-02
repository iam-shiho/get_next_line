/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:23:05 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/02 16:59:54 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd, char *stuck)
{
	ssize_t	read_bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(stuck));
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (ft_free(stuck));
		}
		if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		stuck = ft_strjoin(stuck, buf);
		if (!stuck)
			return (ft_free(buf));
		if (ft_strchr(buf, END))
			break ;
	}
	return (free(buf), stuck);
}

char	*result_str(char *stuck)
{
	int		i;
	char	*str;

	if (!stuck || !stuck[0])
		return (NULL);
	i = 0;
	while (stuck[i] && stuck[i] != END)
		++i;
	str = (char *)malloc(sizeof(char) * (i + 1 + (stuck[i] == END)));
	if (!str)
		return (NULL);
	i = 0;
	while (stuck[i] && stuck[i] != END)
	{
		str[i] = stuck[i];
		++i;
	}
	if (stuck[i] == END)
		str[i++] = END;
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stuck;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stuck = read_buf(fd, stuck);
	if (!stuck || stuck[0] == '\0')
		return (stuck = ft_free(stuck), NULL);
	res = result_str(stuck);
	if (!res)
		return (stuck = ft_free(stuck), NULL);
	stuck = ft_restuck(stuck);
	// if (!stuck)
	// 	return (free(res), NULL);
	// if (stuck && stuck[0] == '\0')
	// 	stuck = ft_free(stuck);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("./1char.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("%s", buf);
	free(buf);
	// buf = read_buf(fd, buf);
	// printf("$%s$", read_buf(fd, buf));
	// printf("#%s#", buf);
	// printf("^%zd^", newline_number(buf));
	buf = get_next_line(fd);
	printf("%s", buf);
	free(buf);
	close(fd);
}
