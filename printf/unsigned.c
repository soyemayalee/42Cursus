/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:29:43 by solee2            #+#    #+#             */
/*   Updated: 2022/12/06 20:31:35 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ui_length(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*unsigned_itoa(unsigned int n)
{
	int		length;
	char	*result;

	length = get_ui_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (n != 0)
	{
		result[length - 1] = (n % 10) + 48;
		n /= 10;
		length--;
	}
	return (result);
}

int	unsigned_printer(unsigned int num)
{
	int		length;
	char	*temp;

	length = 0;
	if (num == 0)
		length += char_printer('0');
	else
	{
		temp = unsigned_itoa(num);
		length += str_printer(temp);
		free(temp);
	}
	return (length);
}
