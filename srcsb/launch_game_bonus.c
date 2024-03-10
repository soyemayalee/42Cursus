/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:47 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:01:46 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_struct(t_info *info, char *file)
{
	info->mlx = NULL;
	info->window = NULL;
	info->file = file;
	info->height = 0;
	info->width = 0;
	info->map = NULL;
	info->player_x = 0;
	info->player_y = 0;
	info->before_x = 0;
	info->before_y = 0;
	info->moves = 0;
	info->item = 0;
	info->exit = 0;
	info->players = 0;
}

void	make_map(t_info *info)
{
	char	*line;
	int		fd;

	fd = open(info->file, O_RDONLY);
	if (fd == -1)
		exit_error("ERROR - File Failed to Open");
	line = get_next_line(fd);
	while (line != NULL)
	{
		info->height++;
		free(line);
		line = get_next_line(fd);
	}
	info->map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (!info->map)
	{
		free(info);
		exit_error("ERROR - Map Allocation Failed");
	}
	close(fd);
}

void	parse_map(t_info *info)
{
	char	*line;
	int		fd;

	fd = open(info->file, O_RDONLY);
	if (fd == -1)
		exit_error("ERROR - File Failed to Open");
	info->height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		info->width = (int)ft_strlen(line);
		if (line[info->width - 1] == '\n')
			info->map[info->height] = ft_substr(line, 0, info->width - 1);
		else
			info->map[info->height] = ft_strdup(line);
		info->height++;
		free(line);
		line = get_next_line(fd);
	}
	info->map[info->height] = NULL;
	close(fd);
}

int	count_item(t_info *info)
{
	char	**map;
	char	*sec;

	map = info->map;
	while (*map)
	{
		sec = *map;
		while (*sec)
		{
			if (*sec == 'C')
				info->item++;
			sec++;
		}
		map++;
	}
	return (info->item);
}

void	initialize_player_position(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'P')
			{
				info->player_x = x;
				info->player_y = y;
			}
			x++;
		}
		y++;
	}
}
