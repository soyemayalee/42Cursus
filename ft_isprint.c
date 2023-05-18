/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:37 by solee2            #+#    #+#             */
/*   Updated: 2022/11/30 23:17:41 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int input)
{
	if (input >= 32 && input < 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char one = 'c';
	char two = ' ';
	char three = '\n';
	char four = '\r';

	printf("Result is %d\n", ft_isprint(one));
	printf("Result is %d\n\n", isprint(one));
	printf("Result is %d\n", ft_isprint(two));
	printf("Result is %d\n\n", isprint(two));
	printf("Result is %d\n", ft_isprint(three));
	printf("Result is %d\n\n", isprint(three));
	printf("Result is %d\n", ft_isprint(four));
	printf("Result is %d\n", isprint(four));
}
*/
