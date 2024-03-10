/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:14:13 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 11:13:37 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			index;
	char		value;
	int			location;
	int			found;

	found = 0;
	value = '\0' + c;
	index = 0;
	location = 0;
	if (!str)
		return ((char *)str);
	if (value == '\0')
		return ((char *)str + ft_strlen((char *)str));
	while (str[index] != '\0')
	{
		if (str[index] == value)
		{
			location = index;
			found = 1;
		}
		index++;
	}
	if (found == 1)
		return ((char *)str + location);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	const char	strone[] = "Hello My Name is Maya. How Are You Doing If I May Ask?";
	const char	strtwo[] = "Hello My Name is Maya. How Are You Doing If I May Ask?";
	const char	chone = 'M';
	const char	chtwo = 'M';
	char	*resultone;
	char	*resulttwo;

	resultone = strrchr(strone, chone);
	resulttwo = ft_strrchr(strtwo, chtwo);

	printf("Correct answer is:\n\t%s\n", resultone);
	printf("My answer is:\n\t%s\n", resulttwo);
}
*/
