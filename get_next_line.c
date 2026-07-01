/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:23:05 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/01 17:09:07 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd, char *stuck)
{
	ssize_t	tmp;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		tmp = read(fd, buf, BUFFER_SIZE);
		if (tmp == -1)
			return (free(buf), free(stuck), NULL);
		if (tmp == 0)
		{
			free(buf);
			break ;
		}
		buf[tmp] = '\0';
		if (newline_number(buf) > -1)
			return (ft_strjoin(stuck, buf));
		stuck = ft_strjoin(stuck, buf);
	}
	return (stuck);
}

ssize_t	newline_number(char *buf)
{
	ssize_t	buf_i;

	buf_i = 0;
	if (!buf)
		return (-1);
	while (buf[buf_i])
	{
		if (buf[buf_i] == END)
			return (buf_i);
		++buf_i;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stuck;
	char		*tmp;
	ssize_t		buf_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stuck = read_buf(fd, stuck); //改行がある文字列か、最後まで読み込んだ文字列がやってくる
	if (stuck == NULL)
		return (NULL);
	buf_i = newline_number(stuck);
	if (buf_i > -1)
	{
		res = result_str(buf_i, stuck); //改行まで
		tmp = ft_strdup(stuck);         // stuckを一旦フリーするため
		free(stuck);
		stuck = new_strlcpy(tmp, buf_i); //あまりを入れる
		free(tmp);
		return (res);
	}
	return (stuck);
}

char	*result_str(size_t buf_i, char *stuck)
{
	char	*res;
	size_t	i;
	size_t	res_len;

	i = 0;
	res_len = buf_i + 1;
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	while (stuck[i] && i < res_len)
	{
		res[i] = stuck[i];
		++i;
	}
	res[i] = '\0';
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
	return (res);
}

int	main(void)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// buf = read_buf(fd, buf);
	// printf("$%s$", read_buf(fd, buf));
	// printf("#%s#", buf);
	// printf("^%zd^", newline_number(buf));
	close(fd);
}
