/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:22:59 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/02 17:56:52 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *stuck, char *buf)
{
	ssize_t	i;
	size_t	j;
	char	*res;

	if (!buf)
		return (ft_free(stuck));
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(stuck) + ft_strlen(buf) + 1));
	if (!res)
		return (ft_free(stuck));
	while (stuck && stuck[i])
	{
		res[i] = stuck[i];
		++i;
	}
	while (buf[j])
	{
		res[i + j] = buf[j];
		++j;
	}
	res[i + j] = '\0';
	free(stuck);
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		++size;
	return (size);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
