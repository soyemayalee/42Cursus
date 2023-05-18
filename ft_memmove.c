/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:43:15 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 10:51:58 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *source, size_t len)
{
	unsigned int	i;

	i = 0;
	if (!dest || !source)
		return (NULL);
	if (dest == source || len == 0)
		return (dest);
	if (source < dest)
	{
		while (0 < len)
		{
			((char *)dest)[len - 1] = ((char *) source)[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)source)[i];
			i++;
		}
	}
	return (dest);
}
