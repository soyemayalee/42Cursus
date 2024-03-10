/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:23:07 by solee2            #+#    #+#             */
/*   Updated: 2022/11/29 21:41:50 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static char	*convert(char *result, long n, int size, int negative)
{
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result[size - 1] = '\0';
	size -= 2;
	while (size >= 0)
	{
		result[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	if (negative == 1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		negative;

	negative = 0;
	if ((long)n == -2147483648)
	{
		result = malloc(12);
		result = convert(result, 2147483648, 12, 1);
		return (result);
	}
	size = get_size(n) + 1;
	if (n < 0)
	{
		negative = 1;
		n = -n;
		size += 1;
	}
	result = malloc(size * sizeof(char));
	if (result == NULL)
		return (NULL);
	else
		result = convert(result, (long)n, size, negative);
	return (result);
}
