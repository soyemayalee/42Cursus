/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:20 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 15:37:01 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int input)
{
	return (input >= 0 && input <= 127);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	one = 'P';
	//char	two = 'Ñ';

	printf("Result is %d\n", ft_isascii(one));
	printf("Result is %d\n\n", isascii(one));
	//printf("Result is %d\n", ft_isascii(two));
	//printf("Result is %d\n\n", isascii(two));
}
*/
