/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:54:52 by solee2            #+#    #+#             */
/*   Updated: 2022/11/30 15:45:06 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char value)
{
	int	count;
	int	frontsep;
	int	index;

	count = 0;
	frontsep = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (frontsep == 1 && str[index] != value)
		{
			count++;
			frontsep = 0;
		}
		else if (frontsep == 0 && str[index] == value)
			frontsep = 1;
		index++;
	}
	return (count);
}

static int	get_start_index(char *str, char set, int number)
{
	int	i;
	int	count;

	count = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != set)
			count++;
		else if (i != 0 && str[i - 1] == set && str[i] != set)
			count++;
		if (count == number)
			return (i);
		i++;
	}
	return (i);
}

static char	*get_word(char *str, char set, int number)
{
	int		start;
	int		index;
	int		end;
	char	*word;

	start = get_start_index(str, set, number);
	end = start;
	while (str[end] != '\0' && str[end] != set)
		end++;
	if (end < start)
		end = ft_strlen(str) - 1;
	index = 0;
	word = malloc(sizeof(char *) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[index] = str[start];
		index++;
		start++;
	}
	word[index] = '\0';
	return (word);
}

char	*add_word(char *src)
{
	int		size;
	int		i;
	char	*dest;

	if (src == NULL)
		return (NULL);
	size = ft_strlen(src);
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
	return (dest);
}

char	**ft_split(const char *str, char set)
{
	char	**strarray;
	int		index;
	char	*temp;

	index = -1;
	strarray = malloc(sizeof(char *) * (count_words((char *)str, set) + 1));
	if (!str || strarray == NULL)
	{
		strarray[0] = ft_calloc(1, 1);
		return (NULL);
	}
	while (++index < count_words((char *)str, set))
	{
		temp = get_word((char *)str, set, index);
		strarray[index] = add_word(temp);
		if (strarray[index] == NULL)
		{
			while (index >= 0)
				free(strarray[index--]);
			free(strarray);
		}
		free(temp);
	}
	strarray[index] = 0;
	return (strarray);
}
