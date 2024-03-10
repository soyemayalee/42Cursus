/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:14 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 12:36:49 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *original, size_t n)
{
	long unsigned int	index;
	char				*cdest;
	const char			*coriginal;

	cdest = (char *)dest;
	coriginal = (char *)original;
	if ((dest == original) || n == 0)
		return (dest);
	if (!dest && !original)
		return (0);
	index = 0;
	while (index < n)
	{
		cdest[index] = coriginal[index];
		index++;
	}
	return (dest);
}
