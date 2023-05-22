/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:36:25 by solee2            #+#    #+#             */
/*   Updated: 2023/05/22 12:35:30 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ignore_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	return (i);
}

long long	atoi_long_long_calc(char temp, long long result)
{
	if (temp < '0' || temp > '9')
	{
		fd_message("ERROR");
		exit(1);
	}
	result = (result * 10) + (temp - '0');
	return (result);
}

long long	atoi_long_long(char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = ignore_space(str);
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i])
	{
		result = atoi_long_long_calc(str[i], result);
		i++;
	}
	if (result * sign < -2147483648 || result * sign > 2147483647)
	{
		fd_message("ERROR");
		exit(1);
	}
	return (result * sign);
}

int	multiple_exist(long long input, char **numbers, int index)
{
	long long	temp;

	index = index + 1;
	while (numbers[index])
	{
		temp = atoi_long_long(numbers[index]);
		if (temp == input)
			return (1);
		index++;
	}
	return (0);
}

void	arg_check(int argc, char **argv)
{
	char		**numbers;
	int			index;
	long long	temp;

	index = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		index = 1;
		numbers = argv;
	}
	while (numbers[index])
	{
		temp = atoi_long_long(numbers[index]);
		if (not_in_range(temp) == 1 || \
		multiple_exist(temp, numbers, index) == 1)
		{
			fd_message("ERROR");
			exit(1);
		}
		index++;
	}
	if (argc == 2)
		ft_free(numbers);
}
