/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:50:05 by solee2            #+#    #+#             */
/*   Updated: 2022/11/29 19:33:02 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	srcsize;
	size_t	j;
	size_t	result;

	srcsize = (size_t)(ft_strlen(src));
	destsize = (size_t)(ft_strlen(dest));
	j = 0;
	while (destsize + j + 1 < size && src[j] != '\0')
	{
		dest[destsize + j] = src[j];
		j++;
	}
	if (size >= destsize)
		dest[destsize + j] = '\0';
	if (size < destsize)
		result = size + srcsize;
	else
		result = srcsize + destsize;
	return (result);
}
/*
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	srcsize;
	size_t	j;
	size_t	result;

	srcsize = (size_t)(ft_strlen(src));
	destsize = (size_t)(ft_strlen(dest));
	if (size < destsize)
		result = size + srcsize;
	else
			result = srcsize + destsize;
	j = 0;
	while (destsize + j + 1 < size && src[j] != '\0')
	{
		dest[destsize + j] = src[j];
		j++;
	}
	dest[destsize + j] = '\0';
	return (result);
}
*/
/*
void	ft_print_result(int n)
{
	char	c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	char	dest[] = "123456789012345";
	ft_memset(dest, 'r', 15);
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);
}
*/
