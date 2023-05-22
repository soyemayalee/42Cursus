/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:56:26 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 20:20:49 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		else if (str[i - 1] == set && str[i] != set)
			count++;
		if (count == number)
			return (i);
		i++;
	}
	return (i);
}

static int	get_end_index(char *str, char set, int start)
{
	while (str[start] != '\0')
	{
		if (str[start] == set)
			return (start);
		start++;
	}
	return (start);
}

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

static char	*get_word(char *str, char set, int number)
{
	int		start;
	int		index;
	int		end;
	char	*word;

	start = get_start_index(str, set, number);
	end = get_end_index(str, set, start);
	if (end < start)
		end = get_length(str) - 1;
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

char	**ft_split(const char *str, char set)
{
	char	**strarray;
	int		wordcount;
	int		index;

	index = 0;
	wordcount = count_words((char *)str, set);
	strarray = malloc(sizeof(char *) * (wordcount + 1));
	if (strarray == NULL)
		return (NULL);
	if (!str)
	{
		strarray[0] = malloc(sizeof(char) * 1);
		strarray[0] = NULL;
		return (strarray);
	}
	while (index < wordcount)
	{
		strarray[index] = add_word(get_word((char *)str, set, index));
		index++;
	}
	strarray[index] = 0;
	return (strarray);
}
