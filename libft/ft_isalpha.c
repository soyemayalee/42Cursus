/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:12 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 11:59:24 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char letter)
{
	int	result;

	result = 1;
	if (letter < 'A' || (letter > 'Z' && letter < 'a') || letter > 'z')
		result = 0;
	return (result);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	one = '+';

	printf("Correct answer:\t%d\n", isalpha(one));
	printf("My answer:\t%d\n", ft_isalpha(one));
}
*/
