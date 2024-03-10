/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:32:19 by solee2            #+#    #+#             */
/*   Updated: 2023/06/02 11:39:56 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gnl_ft_memset(void	*str, int value, size_t number)
{
	unsigned char	*temp;

	temp = str;
	while (number--)
	{
		*temp++ = (unsigned char)value;
	}
	return (str);
}

char	*gnl_ft_strchr(const char *str, int c)
{
	int			index;
	char		value;

	value = '\0' + c;
	index = 0;
	if (value == '\0')
		return ((char *)str + gnl_ft_strlen((char *)str));
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

void	*gnl_ft_calloc(size_t nitems, size_t size)
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
	gnl_ft_memset(ptr, 0, nitems * size);
	return (ptr);
}

size_t	gnl_ft_strlen(const char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
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
	result = malloc(sizeof(char) * ((gnl_ft_strlen(s1) + \
	gnl_ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			result[i] = s1[i];
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[gnl_ft_strlen(s1) + gnl_ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}
