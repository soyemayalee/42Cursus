/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:33:16 by solee2            #+#    #+#             */
/*   Updated: 2022/12/06 20:34:32 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ptr_length(uintptr_t n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}

void	pointer_convert(uintptr_t n)
{
	if (n >= 16)
	{
		pointer_convert(n / 16);
		pointer_convert(n % 16);
	}
	else
	{
		if (n <= 9)
			char_printer(n + '0');
		else
			char_printer(n - 10 + 'a');
	}
}

int	pointer_printer(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
	{
		str_printer("(nil)");
		length += 5;
	}
	else
	{
		str_printer("0x");
		length += 2;
		pointer_convert(ptr);
		length += get_ptr_length(ptr);
	}
	return (length);
}
