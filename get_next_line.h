/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:37:41 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/02 14:14:21 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//# include <stdio.h>
// # include <string.h>
// # include <fcntl.h>

// # define BUFFER_SIZE 42
# define END '\n'

char	*read_buf(int fd, char *stuck);
char	*get_next_line(int fd);
char	*result_str(char *stuck);
char	*ft_strdup(char *stuck);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *stuck, char *buf);
char	*ft_free(char *s);
char	*ft_strchr(char *s, int c);
#endif
