/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:41 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 14:44:58 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper(int initial)
{
	if (initial >= 97 && initial <= 122)
		return (initial - 32);
	else
		return ('\0' + initial);
}
/*
#include <stdio.h>

int	main(void)
{
	char	temp = 'd';

	printf("Result of mine is %c\n", ft_toupper(temp));
}*/
