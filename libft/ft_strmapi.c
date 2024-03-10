/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:11:58 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:30:05 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char const *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*final;
	int				size;

	size = get_length(s);
	final = malloc((size + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		final[index] = (*f)(index, s[index]);
		index++;
	}
	final[index] = '\0';
	return (final);
}
