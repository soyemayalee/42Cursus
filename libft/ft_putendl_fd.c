/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:33 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:21:48 by solee2           ###   ########.fr       */
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

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = get_length(s);
	write(fd, s, length);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	ft_putendl_fd("example string", 1);
}
*/
