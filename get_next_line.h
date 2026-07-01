/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:37:41 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/01 16:19:02 by swaragay         ###   ########.fr       */
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
# define END '\n'

char	*read_buf(int fd, char *stuck);
ssize_t	newline_number(char *buf);
char	*get_next_line(int fd);
char	*result_str(size_t buf_i, char *stuck);
char	*new_strlcpy(char *tmp, ssize_t buf_i);
char	*ft_strdup(char *stuck);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *stuck, char *buf);
#endif
