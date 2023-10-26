/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:35:47 by solee2            #+#    #+#             */
/*   Updated: 2023/10/19 14:40:24 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_whitespace(char c)
{
	if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		neg;
	int		i;

	i = 0;
	while (is_whitespace(str[i]) == 1)
		i++;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -neg;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * 10 < 0)
			return (-1);
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (neg * result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] && s2[i] && diff == 0)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	return (diff);
}
