/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:12:57 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/17 22:41:13 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*hako;
	char		*res;
	static char	*dst;
	int			i;
	int			j;
	int			k;
	int			l;
	static int	size;
	ssize_t		tmp;

	buf = NULL;
	size = 0;
	while (!buf)
	{
		j = 0;
		k = 0;
		if (!buf) //バッファサイズ分読み取る //1
		{
			buf = malloc(BUFFER_SIZE);
			if (!buf)
				return (NULL);
			tmp = read(fd, buf, BUFFER_SIZE);
			if (tmp == -1)
				return ("-1");
		}
		i = 0;
		while (buf[i] != '\n' || buf[i] != EOF || i < (BUFFER_SIZE)) //\nチェック
		{
			++i;
			if (buf[i] == '\n' || buf[i] == EOF) // 改行を見つけた際、returnする文字列の作成 3
			{
				k = 0;
				l = 0;
				res = (char *)malloc(sizeof(char *) * (i + size));
				//\nまでのメモリを確保する
				if (!res)
					return (NULL);
				while (k < size) // dstの中身を代入
				{
					res[k] = dst[k];
					++k;
				}
				while (l < i) // bufの中身を代入
				{
					res[k] = buf[l];
					++k;
					++l;
				}
				free(dst);
				l = 0;
				if (0 < (BUFFER_SIZE - 1) - i)
				{
					dst = (char *)malloc(sizeof(char *) * ((BUFFER_SIZE - 1)
								- i));
					while ((BUFFER_SIZE - 1) - i)
					{
						dst[l] = buf[i];
						++l;
						++i;
					}
				}
				free(buf);
				return (res);
			}
		}
		//もし0文字目で\nがあった場合の対応をする
		//行の文字列の長さを出力する
		hako = malloc(size);
		while (k < size) // dstの中身を代入　buf分ついかしたいから再度mallocをする。
		{
			hako[k] = dst[k];
			++k;
		}
		free(dst);
		dst = NULL;
		/*
		dstにbufを入れていく。
		dstに入っているやつを一回別の場所に移して、free.
		そのあとdst足すiのmallocをしてreturnする文字列を作成する。
		\nがまだない場合は\nがでてくるまでreadを繰り返す
		\nが出てきた場合はreturnする。
		mallocとfreeを繰り返して返すものをつくっていく。
		*/
		size += i;
		dst = (char *)malloc(sizeof(char *) * size);
		if (!dst)
			return (NULL);
		k = 0;
		l = 0;
		while (k < j) // dstの中身を代入
		{
			dst[k] = hako[k];
			++k;
		}
		while (l < i) // bufの中身を代入
		{
			dst[k] = buf[l];
			++k;
			++l;
		}
		free(buf);
		buf = NULL;
		//→もういっかいread
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("./a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}



if (*little == '\0')
	return((char *)big)

if (!*little)
	return((char *)big)
