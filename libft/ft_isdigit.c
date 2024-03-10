/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:29 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 12:33:47 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char input)
{
	int	result;

	result = 1;
	if (input < '0' || input > '9')
		result = 0;
	return (result);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	one = 'P';
	char	two = '9';
	char	three = '0';
	char	four = '+';

	printf("-------For %c-------\n", one);
	printf("Correct Result:\t%d\n", isdigit(one));
	printf("My answer:\t%d\n\n", ft_isdigit(one));
	printf("-------For %c-------\n", two);
	printf("Correct Result:\t%d\n", isdigit(two));
	printf("My answer:\t%d\n\n", ft_isdigit(two));
	printf("-------For %c-------\n", three);
	printf("Correct Result:\t%d\n", isdigit(three));
	printf("My answer:\t%d\n\n", ft_isdigit(three));
	printf("-------For %c-------\n", four);
	printf("Correct Result:\t%d\n", isdigit(four));
	printf("My answer:\t%d\n\n", ft_isdigit(four));
}
*/
