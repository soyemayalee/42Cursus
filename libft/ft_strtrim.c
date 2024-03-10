/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:16:46 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 09:54:17 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char *set, char current)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (current == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		index;
	int		start;
	int		end;

	start = 0;
	while (s1[start] != '\0' && check_set((char *)set, s1[start]) == 1)
		start++;
	end = (int)(ft_strlen((char *)s1));
	while (end > start && check_set((char *)set, s1[end - 1]))
		end--;
	final = (char *)malloc(sizeof(char) * end - start + 1);
	if (final == NULL || !s1)
		return (NULL);
	index = 0;
	while (start < end)
	{
		final[index++] = s1[start++];
	}
	final[index] = '\0';
	return (final);
}
/*
#include <stdio.h>

int main(void)
{
	char	strone[] = " lorem ipsum dolor sit amet";
	char	*strtrim;

	strtrim = ft_strtrim(strone, " l");
	printf("%s\n", strtrim);
}
*/
