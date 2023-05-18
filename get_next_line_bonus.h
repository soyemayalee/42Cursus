/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:38:25 by mayalee           #+#    #+#             */
/*   Updated: 2022/12/24 11:39:49 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*file_reader(int fd, char *result);
char	*getting_line(char *buffer);
char	*getting_next_line(char *buffer);
char	*join_free(char *result, char *buffer);

char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void	*str, int value, size_t number);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);

#endif