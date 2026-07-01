/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:22:59 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/01 17:04:16 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *stuck, char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (!buf)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(stuck) + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	while (stuck[i])
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
	return (res);
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
	while (stuck[i])
	{
		res[i] = stuck[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\0')
		++size;
	return (size);
}
