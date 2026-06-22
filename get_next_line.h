/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:14:36 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/22 13:26:40 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
ssize_t	read_buf(int fd, char *buf);
ssize_t	newline_number(char *buf);
char	ft_strcpy(char *res, char *dst, size_t size);
size_t	ft_strlen(char *s);
size_t	remake_str(char *dst, char *buf, ssize_t buf_i);
char	*result_str(char *buf, size_t buf_i, char *dst, size_t size);

#endif
