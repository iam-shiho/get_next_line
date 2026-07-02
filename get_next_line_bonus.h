/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:37:41 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/02 17:56:24 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef END
#  define END '\n'
# endif

char	*read_buf(int fd, char *stuck);
char	*get_next_line(int fd);
char	*result_str(char *stuck);
char	*ft_restuck(char *stuck);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *stuck, char *buf);
char	*ft_free(char *s);
char	*ft_strchr(char *s, int c);
#endif
