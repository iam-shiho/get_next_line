/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:12:57 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/29 17:18:15 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	remake_str(char *stuck, char *buf, ssize_t buf_i)
{
	size_t	stuck_len;
	size_t	buf_size;
	char	*tmp;

	// tmpにstuck内のなかみを預ける
	stuck_len = ft_strlen(stuck);
	buf_size = buf_i + 1;
	tmp = ft_strdup(stuck);
	stuck = (char *)malloc(sizeof(char) * (stuck_len + buf_size + 1));
	if (!stuck)
		return (-1);
	stuck = ft_strjoin(tmp, buf);
	// ft_strlcpy(stuck, tmp, stuck_len);
	// ft_strlcpy(&stuck[stuck_len], buf, buf_size);
	return (ft_strlen(stuck));
}

// returnする文字列の作成
// stuckのサイズをかぞえたい
char	*result_str(char *buf, size_t buf_i, char *stuck, size_t size)
{
	char	*res;
	char	*tmp;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size + buf_i + 1 + 1));
	if (!res)
		return (NULL);
	tmp = malloc(sizeof(char) * (buf_i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(tmp, buf, buf_i + 1);
	res = ft_strjoin(stuck, tmp);
	// staticの中身の長さとbufの改行文字までのながさをmallocする
	// ft_strlcpy(res, stuck, size);
	// ft_strlcpy(&res[size], buf, buf_i + 1);
	// if (ft_strlen(buf) - buf_i > 0) //余った部分をstaticに入れ込む作業
	// {
	// 	stuck = (char *)malloc(sizeof(char) * ((buf_i + 1) + 1));
	// 	//インデックスのズレと'\0'をいれるため
	// 	ft_strlcpy(stuck, &buf[buf_i], ft_strlen(buf) - buf_i);
	// }
	return (res);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stuck;
	ssize_t			buf_i;
	static ssize_t	stuck_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = NULL;
	buf_i = -1;
	while (buf_i < 0)
	{
		buf = read_buf(fd);
		if (buf == NULL)               // resにstuck分mallocする。strlcpy関数に入れ込んでもいい;
			return (ft_strdup(stuck)); // strdup nisite
		printf("#%s#\n", buf);
		buf_i = newline_number(buf);
		printf("index#%zd#\n", buf_i);
		if (buf_i > -1)
			return (result_str(buf, buf_i, stuck, stuck_len));
		if (stuck == NULL)
		{
			stuck = malloc(ft_strlen(buf) + 1);
			ft_strlcpy(stuck, buf, ft_strlen(buf) + 1);
			printf("stuck1#%s#\n", stuck);
		}
		else
		{
			stuck = ft_strjoin(stuck, buf);
			printf("stuck2#%s#\n", stuck);
		}
		printf("stuck#%s#\n", stuck);
		stuck_len = ft_strlen(stuck);
		printf("len#%zd#\n", stuck_len);
		printf("stuck2##\n");
		buf = NULL;
	}
	return (NULL);
}
// stuckのサイズをはかって,bufの長さをたしたサイズ分mallocし直してstatic変数を更新する。もとからstuck内にある文字列は別のところに移してswapみたいにする。
/*
readで読み込み、読み込みに失敗していないかtmpでかくにんする。
失敗していたらstatic変数の中身を返す。（再度mallocして新しい変数にいれてかえす。freeとNULL文字いれるのを忘れずに）
bufのなかみに改行があったらstaticの中身もたして新しい変数にいれ出力。
なかったらstaticに保存され改行文字またはEOFがでるまでreadを繰り返す。


readでエラーが出た場合はNULLを返す
*/

// stuck_len += (buf_i + 1),

int	main(void)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./a.txt", O_RDONLY);
	get_next_line(fd);
	printf("%s", get_next_line(fd));
	// buf = read_buf(fd, buf);
	// printf("$%s$", read_buf(fd, buf));
	// printf("#%s#", buf);
	// printf("^%zd^", newline_number(buf));
	close(fd);
}

// int	main(void)
// {
// 	char	*str_for_test;
// 	char	*res;

// 	str_for_test = strdup("Hello");
// 	res = ft_strdup(str_for_test);
// 	free(res);
// 	return (0);
// }

// int	main(void)
// {
// 	printf("%s", ft_strdup("Hello"));
// }

// char	*get_next_line(int fd)
// {
// 	char		*buf;
// 	char		*hako;
// 	char		*res;
// 	static char	*stuck;
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
// 		while (buf[i] != END || buf[i] != EOF || i < (BUFFER_SIZE))
// //ENDチェック
// 		{
// 			++i;
// 			if (buf[i] == END || buf[i] == EOF) //
// 改行を見つけた際、returnする文字列の作成 3
// 			{
// 				k = 0;
// 				l = 0;
// 				res = (char *)malloc(sizeof(char *) * (i +
// size));
// 				//ENDまでのメモリを確保する
// 				if (!res)
// 					return (NULL);
// 				while (k < size) // stuckの中身を代入
// 				{
// 					res[k] = stuck[k];
// 					++k;
// 				}
// 				while (l < i) // bufの中身を代入
// 				{
// 					res[k] = buf[l];
// 					++k;
// 					++l;
// 				}
// 				free(stuck);
// 				l = 0;
// 				if (0 < (BUFFER_SIZE - 1) - i)
// 				{
// 					stuck = (char *)malloc(sizeof(char *) *
// ((BUFFER_SIZE - 1)
// 								- i));
// 					while ((BUFFER_SIZE - 1) - i)
// 					{
// 						stuck[l] = buf[i];
// 						++l;
// 						++i;
// 					}
// 				}
// 				free(buf);
// 				return (res);
// 			}
// 		}
// 		//もし0文字目でENDがあった場合の対応をする
// 		//行の文字列の長さを出力する
// 		hako = malloc(size);
// 		while (k < size) //
// stuckの中身を代入　buf分ついかしたいから再度mallocをする。
// 		{
// 			hako[k] = stuck[k];
// 			++k;
// 		}
// 		free(stuck);
// 		stuck = NULL;
// 		/*
// 		stuckにbufを入れていく。
// 		stuckに入っているやつを一回別の場所に移して、free.
// 		そのあとstuck足すiのmallocをしてreturnする文字列を作成する。
// 		ENDがまだない場合はENDがでてくるまでreadを繰り返す
// 		ENDが出てきた場合はreturnする。
// 		mallocとfreeを繰り返して返すものをつくっていく。
// 		*/
// 		size += i;
// 		stuck = (char *)malloc(sizeof(char *) * size);
// 		if (!stuck)
// 			return (NULL);
// 		k = 0;
// 		l = 0;
// 		while (k < j) // stuckの中身を代入
// 		{
// 			stuck[k] = hako[k];
// 			++k;
// 		}
// 		while (l < i) // bufの中身を代入
// 		{
// 			stuck[k] = buf[l];
// 			++k;
// 			++l;
// 		}
// 		free(buf);
// 		buf = NULL;
// 		//→もういっかいread
// 	}
// 	return (NULL);
// }
// static内を更新する
