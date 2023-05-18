/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_num_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:31:50 by solee2            #+#    #+#             */
/*   Updated: 2022/12/06 20:32:54 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_printer(char *s)
{
	int	index;

	index = 0;
	if (!s)
		s = "(null)";
	while (s[index])
	{
		write(1, &s[index], 1);
		index++;
	}
	return (index);
}

int	num_printer(int n)
{
	int		length;
	char	*result;

	length = 0;
	result = ft_itoa(n);
	length = str_printer(result);
	free(result);
	return (length);
}

int	percent_printer(void)
{
	write(1, "%", 1);
	return (1);
}
