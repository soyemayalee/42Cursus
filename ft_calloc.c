/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:48:36 by solee2            #+#    #+#             */
/*   Updated: 2022/11/30 17:58:37 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	char	*temp;

	if (!size || !nitems)
	{
		temp = malloc(sizeof(char));
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (nitems > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nitems * size);
	return (ptr);
}
