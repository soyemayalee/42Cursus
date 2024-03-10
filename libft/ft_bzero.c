/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:40:21 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 12:29:42 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	ft_memset(dst, 0, n);
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

#include <strings.h>

int	main(void)
{
	char	arrone[10] = "ABCDEFG";
	char	arrtwo[10] = "ABCDEFG";

	printer(arrone, 10);
	ft_bzero(arrone, 10);
	printer(arrone, 10);

	printer(arrtwo, 10);
	bzero(arrtwo, 10);
	printer(arrtwo, 10);
}
*/
