/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:58:13 by solee2            #+#    #+#             */
/*   Updated: 2023/04/29 17:10:36 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*join_char(char const s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
void	signal_processor(int pid, unsigned char input);
void	str_processer(int pid, char *original);
void	sighandler(int signum, siginfo_t *siginfo, void *context);

#endif