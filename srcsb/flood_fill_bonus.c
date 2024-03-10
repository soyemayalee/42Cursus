/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:47:46 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:02:02 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	copy_map(t_info *info, \
	char **map_copy)
{
	char	**map;
	char	*sec;
	int		i;
	int		j;

	map = info->map;
	i = 0;
	while (*map)
	{
		j = 0;
		sec = *map;
		while (*sec)
		{
			map_copy[i][j] = *sec;
			sec++;
			j++;
		}
		map++;
		i++;
	}
}

void	fill_map(t_info *info, \
	char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1')
		return ;
	if (map_copy[y][x] == 'C' || map_copy[y][x] == '0' || \
		map_copy[y][x] == 'P' || map_copy[y][x] == 'E')
		map_copy[y][x] = '2';
	if (0 < x + 1 && x + 1 < info->width - 1 && map_copy[y][x + 1] != '2')
		fill_map(info, map_copy, x + 1, y);
	if (0 < y - 1 && y - 1 < info->height - 1 && map_copy[y - 1][x] != '2')
		fill_map(info, map_copy, x, y - 1);
	if (0 < y + 1 && y + 1 < info->height - 1 && map_copy[y + 1][x] != '2')
		fill_map(info, map_copy, x, y + 1);
	if (0 < x - 1 && x - 1 < info->width - 1 && map_copy[y][x - 1] != '2')
		fill_map(info, map_copy, x - 1, y);
}

int	check_path(t_info *info, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	flood_fill_two(t_info *info, char **map_copy)
{
	int	exit;

	copy_map(info, map_copy);
	fill_map(info, map_copy, info->player_x, info->player_y);
	exit = check_path(info, map_copy);
	free_map_copy(map_copy, info->height - 1);
	return (exit);
}

int	flood_fill(t_info *info)
{
	char	**map_copy;
	int		y;

	map_copy = (char **)malloc(info->height * sizeof(char *));
	y = 0;
	while (y < info->height)
	{
		map_copy[y] = (char *)malloc(info->width * sizeof(char));
		if (!map_copy[y])
		{
			free_map_copy(map_copy, y);
			exit_error("ERROR - Malloc Error");
		}
		y++;
	}
	if (flood_fill_two(info, map_copy) == 1)
	{
		free_map(info);
		exit_error("ERROR - Map Does Not Have Valid Path");
	}
	return (0);
}
