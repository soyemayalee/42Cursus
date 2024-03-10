/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:35:07 by solee2            #+#    #+#             */
/*   Updated: 2022/11/29 19:43:38 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *strone, const void *strtwo, size_t n)
{
	unsigned char	*tempone;
	unsigned char	*temptwo;
	unsigned int	i;

	tempone = (unsigned char *)strone;
	temptwo = (unsigned char *)strtwo;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (tempone[i] > temptwo[i])
			return (1);
		else if (tempone[i] < temptwo[i])
			return (-1);
		i++;
	}
	return (0);
}
