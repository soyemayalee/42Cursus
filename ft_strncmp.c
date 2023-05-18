/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:23:44 by solee2            #+#    #+#             */
/*   Updated: 2022/11/30 15:07:19 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;
	int				diff;

	i = 0;
	diff = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (i < n && diff == 0)
	{
		if (diff != 0)
			return (diff);
		diff = one[i] - two[i];
		i++;
	}
	return (diff);
}
/*
int	main(void)
{
	char	strone[] = "test\200";
	char	strtwo[] = "test\0";
	printf("Result is %d\n", ft_strncmp(strone, strtwo, 6));
	//if (ft_strncmp(strone, strtwo, 6) < 0)
		//printf("-1");
}
*/
