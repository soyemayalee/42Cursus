/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:21 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 12:35:44 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*found;

	temp = (unsigned char *)str;
	found = NULL;
	while (str != NULL && n--)
	{
		if (*temp != (unsigned char)c)
			temp++;
		else
		{
			found = temp;
			break ;
		}
	}
	return (found);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	one[] = "this is an example sentence";
	char	valueone = 'i';

	char	*finalone = memchr(one, valueone, strlen(one)+1);
	printf("The answer is\n\t%s\n", finalone);

	char	two[] = "this is an example sentence";
	char	valuetwo = 'i';

	char	*finaltwo = ft_memchr(two, valuetwo, strlen(two) + 1);
	printf("My answer is\n\t%s\n", finaltwo);
}*/
