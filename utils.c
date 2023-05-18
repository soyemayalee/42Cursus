/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:35:29 by solee2            #+#    #+#             */
/*   Updated: 2023/04/29 17:10:04 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*join_char(char const s1, char const *s2)
{
	char	*final;
	int		lengthtwo;
	int		index;
	int		temp;

	lengthtwo = (int)(ft_strlen((char *)s2));
	final = malloc(sizeof(char) * (1 + lengthtwo + 1));
	if ((!s1 && !s2) || final == NULL)
		return (NULL);
	final[0] = s1;
	index = 1;
	temp = 0;
	while (s2[temp] != '\0')
		final[index++] = s2[temp++];
	final[index] = '\0';
	return (final);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while ((str[i]))
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n);
}
