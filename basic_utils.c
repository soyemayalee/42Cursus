/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:50:40 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 20:20:45 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		negative = 1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = get_length(s);
	write(fd, s, length);
	write(fd, "\n", 1);
}

int	ft_streq(char *one, char *two)
{
	int	size_one;
	int	size_two;
	int	i;

	size_one = get_length(one);
	size_two = get_length(two);
	if (size_one != size_two)
		return (1);
	i = 0;
	while (one[i] && two[i])
	{
		if (one[i] != two[i])
			return (1);
		i++;
	}
	return (0);
}
