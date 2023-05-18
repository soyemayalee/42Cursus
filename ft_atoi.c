/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:41:38 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 11:15:45 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_range(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
	{
		return (1);
	}
	else
		return (0);
}

static int	number_range(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	negative;

	negative = 0;
	i = 0;
	n = 0;
	while (space_range(str[i]))
		i++;
	if (str[i] == '-')
	{
		negative++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (number_range(str[i]))
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (negative % 2 == 1)
		return (-n);
	return (n);
}
