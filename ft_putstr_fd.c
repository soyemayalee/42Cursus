/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:53:51 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:22:30 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = get_length(s);
	write(fd, s, length);
}
/*
int	main(void)
{
	ft_putstr_fd("this string", 1);
}
*/
