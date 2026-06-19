/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:17:22 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/19 12:10:32 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_buf(int fd, char *buf) //ファイルを読み込む
{
	ssize_t tmp;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	tmp = read(fd, buf, BUFFER_SIZE);
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
	size_t	buf_i;

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
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0' || s[size] != '\n') //改行があるのか気にする
		++size;
	return (size);
}

size_t	remake_str(char *dst, char *buf, ssize_t buf_i) // static内を更新する
{
	size_t dst_size;
	size_t buf_size;
	size_t i;
	char *tmp;

	dst_size = ft_strlen(dst);
	buf_size = ft_strlen(buf[buf_i]);
	tmp = (char *)malloc(sizeof(char *) * dst_size + 1); // tmpにdst内のなかみを預ける
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, dst, dst_size);
	dst = (char *)malloc(sizeof(char *) * dst_size + buf_size + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, tmp, dst_size);
	ft_strcpy(dst[dst_size], buf, buf_size);
	return (ft_strlen(dst));
}

// returnする文字列の作成
// dstのサイズをかぞえたい
char	*result_str(char *buf, size_t buf_i, char *dst, size_t size)
{
	char	*res;
	size_t	res_len;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char *) * (size + buf_i + 1));
	if (!res)
		return (NULL);
	// staticの中身の長さとbufの改行文字までのながさをmallocする
	res_len = ft_strcpy(res, dst);
	while (i == buf_i)
	{
		res[res_len + i] = buf[i];
		++i;
	}
	size = 0;
	if (ft_slen(buf) - buf_i > 0) //余った部分をstaticに入れ込む作業
	{
		dst = (char *)malloc(sizeof(char *) * ((buf_i + 1) + 1));
		//インデックスのズレと'\0'をいれるため
		size = ft_strcpy(dst, buf[buf_i]);
	}
	return (res);
}
