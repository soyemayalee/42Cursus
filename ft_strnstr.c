/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:16:36 by solee2            #+#    #+#             */
/*   Updated: 2022/11/23 13:30:55 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*target == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (target[j] != '\0' && target[j] == str[i + j])
			j++;
		if (target[j] == '\0' && i + j - 1 < len)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
	//bsd/string.h and then when compiling, use -lbsd..
	
int	main(void)
{
	char	strone[] = "hello My name is Maya how are you doing";
	char	targetone[] = "M";
	char	strtwo[] = "hello My name is Maya how are you doing";
	char	targettwo[] = "M";

	printf("Correct answer is\n\t%s\n", strnstr(strone, targetone, 20));
	printf("My answer is\n\t%s\n", ft_strnstr(strtwo, targettwo, 20));
}
*/
