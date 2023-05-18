/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:27:57 by mayalee           #+#    #+#             */
/*   Updated: 2022/12/06 20:27:41 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_printer(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check_format(va_list args, const char temp)
{
	int	length;

	length = 0;
	if (temp == 'c')
		length += char_printer(va_arg(args, int));
	else if (temp == 's')
		length += str_printer(va_arg(args, char *));
	else if (temp == 'p')
		length += pointer_printer(va_arg(args, unsigned long long));
	else if (temp == 'd' || temp == 'i')
		length += num_printer(va_arg(args, int));
	else if (temp == 'u')
		length += unsigned_printer(va_arg(args, unsigned int));
	else if (temp == 'x' || temp == 'X')
		length += hex_printer(va_arg(args, unsigned int), temp);
	else if (temp == '%')
		length += percent_printer();
	return (length);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			length += check_format(args, input[i + 1]);
			i++;
		}
		else
			length += char_printer(input[i]);
		i++;
	}
	va_end(args);
	return (length);
}
