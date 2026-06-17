/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:17:22 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/17 22:30:18 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	read_buf(int fd, char *buf) //ファイルを読み込む
{
	ssize_t tmp;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	tmp = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (tmp == -1)
		return ("error"); //なんて返そうかな
	return (buf);
}

// int	next_line_checker(char *buf)
// //\nを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
// {
// 	size_t i;
// 	char *res;
// 	i = 0;
// 	while (buf[i] != '\n' || buf[i] != EOF || i < BUFFER_SIZE)
// 	//基本バッファサイズ分回る
// 	{
// 		i++;
// 		if (buf[i] == '\n' || buf[i] == EOF || i < BUFFER_SIZE)
// 			// bufのなかに\nが見つかった場合
// 			return (i);
// 	}
// 	if (buf[0] == '\n' || buf[0] == EOF)
// 		return (0);
// 	return (-1); //バッファサイズ分回したけど\nがはいっていなかった。
// }
//正の数だった場合はそのままstatic内のものも足してmallocして文字列を作成する。
//負の数だった場合はsizeにバッファサイズを足して、staticにも読み込んだ文字を入れる

//文字列の移行
char	ft_strcpy(char *res, char *dst, size_t i)
{
	while (i--)
	{
		*res = *dst;
		++res;
		++dst;
	}
	free(dst);
	return (res);
}

//\nを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
size_t	newline_number(char *buf)
{
	size_t buf_i;

	buf_i = 0;
	while (buf[buf_i])
	{
		if (buf[buf_i] == '\n')
			return (buf_i);
		++buf_i;
	}
	return (-1);
}

//returnする文字列の作成
char	result_str(char *buf, size_t buf_i, char *dst, size_t size)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char *) * (size + (buf_i + 1)));
	// indexのズレで＋1する
	while (i < size)
	{
		res[i] = dst[i];
		++i;
	}
	while (j == buf_i)
	{
		res[i + j] = buf[j];
		++j;
	}
	return(res);
}
