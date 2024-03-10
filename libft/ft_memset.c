/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:18:35 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:21:17 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*str, int value, size_t number)
{
	unsigned char	*temp;

	temp = str;
	while (number--)
	{
		*temp++ = (unsigned char)value;
	}
	return (str);
}
/*
#include <stdio.h>

void	printer(char arr[], int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		printf("%c\n", arr[index]);
		index++;
	}
	printf("\n");
}

#include <string.h>
int	main(void)
{
	char	arrone[5] = "ABCD";
	char	arrtwo[5] = "ABCD";

	printer(arrone, 5);
	ft_memset(arrone, '+', sizeof(arrone));
	printer(arrone, 5);

	printer(arrtwo, 5);
	memset(arrtwo, '+', sizeof(arrtwo));
	printer(arrtwo, 5);
}
*/
