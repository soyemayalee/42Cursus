/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:42:24 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 14:44:22 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*final;
	int				size;
	unsigned int	j;

	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > (size_t)(ft_strlen((char *)s)))
		size = (size_t)(ft_strlen((char *)s));
	else if (len > (size_t)(ft_strlen((char *)s)) - start + 1)
		size = len - (size_t)start;
	else
		size = len;
	final = malloc(sizeof(char) * (size + 1));
	if (final == NULL)
		return (NULL);
	j = 0;
	while (s[j + start] != '\0' && j < len)
	{
		final[j] = s[j + start];
		j++;
	}
	final[j] = '\0';
	return (final);
}
/*
#include <stdio.h>

int	main(void)
{
	char	strone[] = "hello my name is Maya how are you doing";
	//char	strtwo[] = "Hello";

	printf("Original sentence:\n\t%s\n", strone);
	printf("My answer is\n\t%s\n", ft_substr(strone, 0, 20));
}
*/
