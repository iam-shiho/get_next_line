/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:23:05 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/02 17:59:34 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buf(int fd, char *stuck)
{
	ssize_t	read_bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	free(buf);
	return (stuck);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stuck[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!stuck[fd] || !ft_strchr(stuck[fd], END))
		stuck[fd] = read_buf(fd, stuck[fd]);
	if (!stuck[fd])
		return (NULL);
	res = result_str(stuck[fd]);
	if (!res)
	{
		free(stuck[fd]);
		stuck[fd] = NULL;
		return (NULL);
	}
	stuck[fd] = ft_restuck(stuck[fd]);
	return (res);
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

char	*ft_restuck(char *stuck)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (stuck[i] && stuck[i] != END)
		++i;
	if (!stuck[i] || !stuck[i + 1])
		return (ft_free(stuck));
	res = (char *)malloc(sizeof(char) * (ft_strlen(stuck) - i));
	if (!res)
		return (ft_free(stuck));
	j = 0;
	++i;
	while (stuck[i])
		res[j++] = stuck[i++];
	res[j] = '\0';
	free(stuck);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	fd = open("./variable_nls.txt", O_RDONLY);
// 	buf = get_next_line(fd);
// 	printf("%s", buf);
// 	free(buf);
// 	// buf = read_buf(fd, buf);
// 	// printf("$%s$", read_buf(fd, buf));
// 	// printf("#%s#", buf);
// 	// printf("^%zd^", newline_number(buf));
// 	buf = get_next_line(fd);
// 	printf("%s", buf);
// 	free(buf);
// 	buf = get_next_line(fd);
// 	printf("%s", buf);
// 	free(buf);
// 	close(fd);
// }
