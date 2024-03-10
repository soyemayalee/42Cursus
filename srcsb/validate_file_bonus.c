/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:35:30 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:01:32 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	hidden_file(char *s1, char *s2)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == '/')
			j = i;
		i++;
	}
	p = 0;
	j++;
	while (s1[j] && s2[p])
	{
		if (s1[j] != s2[p])
			return (0);
		j++;
		p++;
	}
	return (1);
}

void	validate_file(int argc, char *file)
{
	int	fd;

	if (argc != 2)
		exit_error("ERROR - Wrong Number of Arguments");
	if (hidden_file(file, ".ber") == 1)
		exit_error("ERROR - Hidden File");
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		exit_error("ERROR - Wrong File Extension");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("ERROR - File Could Not Be Opened");
}
