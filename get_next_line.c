/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:23:05 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/01 20:56:15 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd, char *stuck)
{
	ssize_t	read_bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
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
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stuck = read_buf(fd, stuck);
	if (stuck == NULL)
		return (NULL);
	res = result_str(stuck);
	tmp = stuck;
	stuck = ft_strdup(&stuck[ft_strlen(res)]);
	ft_free(tmp);
	if (stuck && stuck[0] == '\0')
		stuck = ft_free(stuck);
	return (res);
}

char	*new_strlcpy(char *tmp, ssize_t buf_i)
{
	size_t	i;
	size_t	j;
	size_t	tmp_len;
	char	*res;

	tmp_len = ft_strlen(tmp) - buf_i;
	res = (char *)malloc(sizeof(char) * (tmp_len + 1));
	i = buf_i + 1;
	j = 0;
	while (tmp[i] != '\0')
	{
		res[j] = tmp[i];
		++i;
		++j;
	}
	res[j] = '\0';
	free(tmp);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	fd = open("./a.txt", O_RDONLY);
// 	buf = get_next_line(fd);
// 	printf("%s", buf);
// 	// buf = read_buf(fd, buf);
// 	// printf("$%s$", read_buf(fd, buf));
// 	// printf("#%s#", buf);
// 	// printf("^%zd^", newline_number(buf));
// 	free(buf);
// 	close(fd);
// }
