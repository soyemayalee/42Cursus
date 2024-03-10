/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:14 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 00:41:32 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_shape(t_info *info)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (info->map[i])
	{
		length = (int)ft_strlen(info->map[i]);
		if (info->width != length)
			return (0);
		i++;
	}
	if (info->height != i)
		return (0);
	return (1);
}

int	map_content(t_info *info)
{
	char	**map;
	char	*sec;

	map = info->map;
	while (*map)
	{
		sec = *map;
		while (*sec)
		{
			if (*sec == 'P')
				info->players = info->players + 1;
			else if (*sec == 'E')
				info->exit = info->exit + 1;
			else if (*sec != '1' && *sec != '0' && *sec != 'C')
				return (0);
			sec++;
		}
		map++;
	}
	if (info->item < 1 || info->players != 1 || info->exit != 1)
		return (0);
	return (1);
}

int	map_vertical_walls(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		if (info->map[i][0] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < info->height)
	{
		if (info->map[j][info->width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_horizontal_walls(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[0][i])
	{
		if (info->map[0][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (info->map[info->height - 1][j])
	{
		if (info->map[info->height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_is_valid(t_info *info)
{
	if (info->height < 3 || info->width < 3)
		return (0);
	else if (map_shape(info) == 0)
		return (0);
	else if (map_content(info) == 0)
		return (0);
	else if (map_vertical_walls(info) == 0 || map_horizontal_walls(info) == 0)
		return (0);
	else if (flood_fill(info) != 0)
		return (0);
	return (1);
}
