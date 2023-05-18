/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:45 by solee2            #+#    #+#             */
/*   Updated: 2022/11/29 19:28:43 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	one[] = "test";
	char	two[] = "a";
	char	three[] = "+234dsa";

	printf("Length of test is %ld\n", ft_strlen(one));
	printf("Length of test is %ld\n\n", strlen(one));
	printf("Length of a is %ld\n", ft_strlen(two));
	printf("Length of a is %ld\n\n", strlen(two));
	printf("Length of +234dsa is %ld\n", ft_strlen(three));
	printf("Length of +234dsa is %ld\n", strlen(three));
}
*/
