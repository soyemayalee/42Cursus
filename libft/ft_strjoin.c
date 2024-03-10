/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:58:11 by solee2            #+#    #+#             */
/*   Updated: 2022/11/28 09:52:28 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		lengthone;
	int		lengthtwo;
	int		index;
	int		temp;

	lengthone = (int)(ft_strlen((char *)s1));
	lengthtwo = (int)(ft_strlen((char *)s2));
	final = malloc(sizeof(char) * (lengthone + lengthtwo + 1));
	if ((!s1 && !s2) || final == NULL)
		return (NULL);
	index = 0;
	temp = 0;
	while (s1[index] != '\0')
	{
		final[index] = s1[index];
		index++;
	}
	temp = 0;
	while (s2[temp] != '\0')
		final[index++] = s2[temp++];
	final[index] = '\0';
	return (final);
}
/*
#include <stdio.h>
int	main(void)
{
	char	strone[] = "hello my name is Maya";
	char	strtwo[] = "how are you doing";

	printf("final result\n\t%s\n", ft_strjoin(strone, strtwo));
}
*/
