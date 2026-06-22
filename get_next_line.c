/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:12:57 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/22 15:56:33 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char		*buf;
// 	char		*hako;
// 	char		*res;
// 	static char	*dst;
// 	int			i;
// 	int			j;
// 	int			k;
// 	int			l;
// 	static int	size;
// 	ssize_t		tmp;

// 	buf = NULL;
// 	size = 0;
// 	while (!buf)
// 	{
// 		j = 0;
// 		k = 0;
// 		if (!buf) //バッファサイズ分読み取る //1
// 		{
// 			buf = malloc(BUFFER_SIZE);
// 			if (!buf)
// 				return (NULL);
// 			tmp = read(fd, buf, BUFFER_SIZE);
// 			if (tmp == -1)
// 				return ("-1");
// 		}
// 		i = 0;
// 		while (buf[i] != '\n' || buf[i] != EOF || i < (BUFFER_SIZE)) //\nチェック
// 		{
// 			++i;
// 			if (buf[i] == '\n' || buf[i] == EOF) // 改行を見つけた際、returnする文字列の作成 3
// 			{
// 				k = 0;
// 				l = 0;
// 				res = (char *)malloc(sizeof(char *) * (i + size));
// 				//\nまでのメモリを確保する
// 				if (!res)
// 					return (NULL);
// 				while (k < size) // dstの中身を代入
// 				{
// 					res[k] = dst[k];
// 					++k;
// 				}
// 				while (l < i) // bufの中身を代入
// 				{
// 					res[k] = buf[l];
// 					++k;
// 					++l;
// 				}
// 				free(dst);
// 				l = 0;
// 				if (0 < (BUFFER_SIZE - 1) - i)
// 				{
// 					dst = (char *)malloc(sizeof(char *) * ((BUFFER_SIZE - 1)
// 								- i));
// 					while ((BUFFER_SIZE - 1) - i)
// 					{
// 						dst[l] = buf[i];
// 						++l;
// 						++i;
// 					}
// 				}
// 				free(buf);
// 				return (res);
// 			}
// 		}
// 		//もし0文字目で\nがあった場合の対応をする
// 		//行の文字列の長さを出力する
// 		hako = malloc(size);
// 		while (k < size) // dstの中身を代入　buf分ついかしたいから再度mallocをする。
// 		{
// 			hako[k] = dst[k];
// 			++k;
// 		}
// 		free(dst);
// 		dst = NULL;
// 		/*
// 		dstにbufを入れていく。
// 		dstに入っているやつを一回別の場所に移して、free.
// 		そのあとdst足すiのmallocをしてreturnする文字列を作成する。
// 		\nがまだない場合は\nがでてくるまでreadを繰り返す
// 		\nが出てきた場合はreturnする。
// 		mallocとfreeを繰り返して返すものをつくっていく。
// 		*/
// 		size += i;
// 		dst = (char *)malloc(sizeof(char *) * size);
// 		if (!dst)
// 			return (NULL);
// 		k = 0;
// 		l = 0;
// 		while (k < j) // dstの中身を代入
// 		{
// 			dst[k] = hako[k];
// 			++k;
// 		}
// 		while (l < i) // bufの中身を代入
// 		{
// 			dst[k] = buf[l];
// 			++k;
// 			++l;
// 		}
// 		free(buf);
// 		buf = NULL;
// 		//→もういっかいread
// 	}
// 	return (NULL);
// }

size_t	remake_str(char *dst, char *buf, ssize_t buf_i) // static内を更新する
{
	size_t dst_size;
	size_t buf_size;
	char *tmp;

	dst_size = ft_strlen(dst);
	buf_size = buf_i + 1;
	tmp = (char *)malloc(sizeof(char) * (dst_size + 1)); // tmpにdst内のなかみを預ける
	if (!tmp)
		return (-1);
	ft_strcpy(tmp, dst, dst_size);
	dst = (char *)malloc(sizeof(char) * (dst_size + buf_size + 1));
	if (!dst)
		return (-1);
	ft_strcpy(dst, tmp, dst_size);
	ft_strcpy(&dst[dst_size], buf, buf_size);
	return (ft_strlen(dst));
}

// returnする文字列の作成
// dstのサイズをかぞえたい
char	*result_str(char *buf, size_t buf_i, char *dst, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	// staticの中身の長さとbufの改行文字までのながさをmallocする
	ft_strcpy(res, dst, size);
	ft_strcpy(&res[size], buf, buf_i + 1);
	if (ft_strlen(buf) - buf_i > 0) //余った部分をstaticに入れ込む作業
	{
		dst = (char *)malloc(sizeof(char) * ((buf_i + 1) + 1));
		//インデックスのズレと'\0'をいれるため
		ft_strcpy(dst, &buf[buf_i], ft_strlen(buf) - buf_i);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*res;
	static char		*dst;
	ssize_t			tmp;
	ssize_t			buf_i;
	static ssize_t	dst_size;

	res = NULL;
	buf = NULL;
	tmp = -1;
	while (tmp < 0)
	{
		tmp = 0;
		tmp = read_buf(fd, buf);
		if (tmp == 0) // resにdst分mallocする。strlcpy関数に入れ込んでもいい;
			return (strcpy(res, dst)); //strdup nisite
		buf_i = newline_number(buf);
		if (buf_i > -1)
		{
			return (dst_size += (buf_i + 1), result_str(buf, buf_i, dst,
					dst_size));
		}
		tmp = remake_str(dst, buf, buf_i);
		if (tmp == -1)
			return (NULL);
		dst_size += tmp;
	}
	return (NULL);
}
// dstのサイズをはかって,bufの長さをたしたサイズ分mallocし直してstatic変数を更新する。もとからdst内にある文字列は別のところに移してswapみたいにする。
/*
readで読み込み、読み込みに失敗していないかtmpでかくにんする。
失敗していたらstatic変数の中身を返す。（再度mallocして新しい変数にいれてかえす。freeとNULL文字いれるのを忘れずに）
bufのなかみに改行があったらstaticの中身もたして新しい変数にいれ出力。
なかったらstaticに保存され改行文字またはEOFがでるまでreadを繰り返す。


readでエラーが出た場合はNULLを返す
*/

int	main(void)
{
	int	fd;

	fd = open("./a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
