/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:49:40 by solee2            #+#    #+#             */
/*   Updated: 2023/05/18 10:31:57 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	not_in_range(long long input)
{
	if (input < -2147483648 || input > 2147483647)
		return (1);
	return (0);
}

int	is_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*add_word(char *src)
{
	int		size;
	int		i;
	char	*dest;

	size = get_length(src);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}
