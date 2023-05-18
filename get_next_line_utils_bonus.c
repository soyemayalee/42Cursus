/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:32:19 by solee2            #+#    #+#             */
/*   Updated: 2022/12/24 11:39:12 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void	*str, int value, size_t number)
{
	unsigned char	*temp;

	temp = str;
	while (number--)
	{
		*temp++ = (unsigned char)value;
	}
	return (str);
}

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

size_t	ft_strlen(const char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			result[i] = s1[i];
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}
