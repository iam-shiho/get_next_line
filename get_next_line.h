/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:14:36 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/23 12:51:34 by swaragay         ###   ########.fr       */
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
char	*read_buf(int fd, char *buf);
ssize_t	newline_number(char *buf);
void	ft_strlcpy(char *res, char *stuck, size_t size);
size_t	ft_strlen(char *s);
size_t	remake_str(char *stuck, char *buf, ssize_t buf_i);
char	*result_str(char *buf, size_t buf_i, char *stuck, size_t size);
char	*ft_strdup(char *s);

#endif
