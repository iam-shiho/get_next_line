/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:17:22 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/29 17:18:05 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ファイルを読み込む
char	*read_buf(int fd)
{
	ssize_t	tmp;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1); //'\0'入れるための＋１
	if (!buf)
		return (NULL);
	tmp = read(fd, buf, BUFFER_SIZE);
	if (tmp > 0)
		buf[tmp] = '\0';
	else if (tmp <= 0)
		return (NULL);
	return (buf);
}

// ENDを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
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

//文字列の移行かつ文字数のカウント(文字すカウントはいらない気がする)　もしresがNULLだった場合mallocするってしたら良さげな気がする。 最初になん文字resい入ってるかの処理もあったらいい気がする
// buf内の改行文字までwhileが回るようにsize指定をした。
void	ft_strlcpy(char *res, char *stuck, size_t size)
{
	size_t	i;

	if (size == 0)
		return ;
	i = 0;
	while (stuck[i] != '\0' && i < size - 1)
	{
		res[i] = stuck[i];
		++i;
	}
	res[i] = '\0';
	free(stuck);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\0') //改行があるのか気にする
		++size;
	return (size);
}

char	*ft_strdup(char *stuck)
{
	size_t			len;
	char			*res;
	unsigned int	i;

	i = 0;
	len = ft_strlen(stuck);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, stuck, len + 1);
	return (res);
}

char	*ft_strjoin(char *stuck, char *buf)
{
	size_t			stuck_len;
	size_t			buf_len;
	unsigned int	i;
	unsigned int	j;
	char			*res;

	i = 0;
	j = 0;
	if (!stuck || !buf)
		return (NULL);
	stuck_len = ft_strlen(stuck);
	buf_len = ft_strlen(buf);
	res = malloc(sizeof(char) * (stuck_len + buf_len + 1));
	if (!res)
		return (NULL);
	stuck = ft_strdup(stuck);
	buf = ft_strdup(buf);
	ft_strlcpy(res, stuck, stuck_len + 1);
	ft_strlcpy(&res[stuck_len], buf, buf_len + 1);
	stuck = NULL;
	buf = NULL;
	return (res);
}
// int	next_line_checker(char *buf)
// //ENDを検知する あった場合その文字列のインデックスを返す。 比べるときは比べるものを−１する bufの長さもわかる
// {
// 	size_t i;
// 	char *res;
// 	i = 0;
// 	while (buf[i] != END || buf[i] != EOF || i < BUFFER_SIZE)
// 	//基本バッファサイズ分回る
// 	{
// 		i++;
// 		if (buf[i] == END || buf[i] == EOF || i < BUFFER_SIZE)
// 			// bufのなかにENDが見つかった場合
// 			return (i);
// 	}
// 	if (buf[0] == END || buf[0] == EOF)
// 		return (0);
// 	return (-1); //バッファサイズ分回したけどENDがはいっていなかった。
// }
//正の数だった場合はそのままstatic内のものも足してmallocして文字列を作成する。
//負の数だった場合はsizeにバッファサイズを足して、staticにも読み込んだ文字を入れる
