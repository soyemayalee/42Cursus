/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:28:06 by solee2            #+#    #+#             */
/*   Updated: 2022/12/06 20:29:20 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_length(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n /= 16;
	}
	return (length);
}

void	hex_convert(unsigned int n, const char temp)
{
	char	*base;

	if (temp == 'x')
		base = "0123456789abcdef";
	else if (temp == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		hex_convert(n / 16, temp);
		hex_convert(n % 16, temp);
	}
	else
	{
		char_printer(base[n % 16]);
	}
}

int	hex_printer(unsigned int n, const char temp)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		char_printer('0');
		return (1);
	}
	else
		hex_convert(n, temp);
	length += get_hex_length(n);
	return (length);
}
