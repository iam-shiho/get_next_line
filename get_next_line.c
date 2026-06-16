/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:12:57 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/16 20:55:56 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*s;
	static char	*dst;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;
	static int	size;
	ssize_t		tmp;

	size = 0;
	if (!buf) //バッファサイズ分読み取る
	{
		buf = malloc(BUFFER_SIZE);
		if (!buf)
			return (NULL);
		tmp = read(fd, buf, BUFFER_SIZE);
		if (tmp == -1)
			return (-1);
	}
	while (buf[i] != '\n' || buf[i] != EOF || i > BUFFER_SIZE) //\nチェック
	{
		i = 0;
		++i;
		buf[i];
		if (buf[i] == '\n' || buf[i] == EOF)
		{
			j = 0;
			k = 0;
			l = 0;
			while (j < size) // staticに入っている文字列の長さを計算する。
			{
				dst[j]; // malloc
				++j;
			}
			s = malloc(i + j); //\nまでのメモリを確保する
			if (!s)
				return (NULL);
			while (k < i) // buf
			{
				s[k] = dst[k];
				++k;
			}
			while (l < j)
			{
				s[k] = dst[l];
				++k;
				++l;
			}
			free(buf);
			free(dst);
			return (s);
		}
	}
	size += i;
	/*
	dstにbufを入れていく。
	dstに入っているやつを一回別の場所に移して、free.
	そのあとdst足すiのmallocをしてreturnする文字列を作成する。
	\nがまだない場合は\nがでてくるまでreadを繰り返す
	\nが出てきた場合はreturnする。
	mallocとfreeを繰り返して返すものをつくっていく。
	*/
	dst = malloc(size);
	if(!dst)
		return(NULL);
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("./a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
