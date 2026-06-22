/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:17:22 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/22 14:33:31 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_buf(int fd, char *buf) //ファイルを読み込む
{
	ssize_t tmp;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	tmp = read(fd, buf, BUFFER_SIZE);
	if(tmp )
	buf[BUFFER_SIZE] = '\0';
	return (tmp);
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

//\nを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
ssize_t	newline_number(char *buf)
{
	ssize_t	buf_i;

	buf_i = 0;
	while (buf[buf_i])
	{
		if (buf[buf_i] == '\n')
			return (buf_i);
		++buf_i;
	}
	return (-1);
}

//文字列の移行かつ文字数のカウント(文字すカウントはいらない気がする)　もしresがNULLだった場合mallocするってしたら良さげな気がする。 最初になん文字resい入ってるかの処理もあったらいい気がする
// buf内の改行文字までwhileが回るようにsize指定をした。
char	ft_strcpy(char *res, char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < size)
	{
		res[i] = dst[i];
		++i;
	}
	res[i] = '\0';
	free(dst);
	dst = NULL;
	return (*res);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0' || s[size] != '\n') //改行があるのか気にする
		++size;
	return (size);
}
