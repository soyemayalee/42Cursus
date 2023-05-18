/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:14:23 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:27:47 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int			index;
	char		value;

	value = '\0' + c;
	index = 0;
	if (value == '\0')
		return ((char *)str + ft_strlen((char *)str));
	while (str[index] != '\0')
	{
		if (str[index] == value)
			return ((char *)str + index);
		index++;
	}
	if (str[index] == value)
		return ((char *)str + index);
	return (NULL);
}
