/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:04 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 12:32:35 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char input)
{
	int	result;

	result = 0;
	if (input >= 'A' && input <= 'Z')
		result = 1;
	else if (input >= 'a' && input <= 'z')
		result = 1;
	else if (input >= '0' && input <= '9')
		result = 1;
	return (result);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	one = 'P';
	char	two = 'w';
	char	three = '4';
	char	four = '=';

	printf("Result is %d\n", ft_isalnum(one));
	printf("Result is %d\n\n", isalnum(one));
	printf("Result is %d\n", ft_isalnum(two));
	printf("Result is %d\n\n", isalnum(two));
	printf("Result is %d\n", ft_isalnum(three));
	printf("Result is %d\n\n", isalnum(three));
	printf("Result is %d\n", ft_isalnum(four));
	printf("Result is %d\n", isalnum(four));
}
*/
