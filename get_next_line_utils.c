/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:17:22 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/23 13:27:50 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ファイルを読み込む
char	*read_buf(int fd, char *buf)
{
	ssize_t	tmp;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	if (!buf)
		return (NULL);
	tmp = read(fd, buf, BUFFER_SIZE);
	if (tmp > 0)
		buf[tmp] = '\0';
	else if (tmp <= 0)
		return (buf = NULL);
	return (buf);
}

//\nを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
ssize_t	newline_number(char *buf)
{
	ssize_t	buf_i;

	buf_i = 0;
	if (!buf)
		return (-1);
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
void	ft_strlcpy(char *res, char *stuck, size_t size)
{
	size_t	i;

	i = 0;
	while (stuck[i] != '\0' && i < size)
	{
		res[i] = stuck[i];
		++i;
	}
	res[i] = '\0';
	free(stuck);
	stuck = NULL;
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (-1);
	while (s[size] != '\0') //改行があるのか気にする
		++size;
	return (size);
}

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
	free(s);
	s = NULL;
	return (dest);
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
