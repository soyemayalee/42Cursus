/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:57 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:01:41 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_xpm(t_info *info)
{
	static char	*imgs[5] = {"./image/wall.xpm", "./image/back.xpm", \
	"./image/player.xpm", "./image/item.xpm", "./image/exit.xpm"};
	int			i;
	int			j;
	int			p;
	int			q;

	i = -1;
	j = -1;
	while (++i < 5)
	{
		info->xpm_images[i].image = mlx_xpm_file_to_image(info->mlx, \
		imgs[i], &p, &p);
		if (!info->xpm_images[i].image)
		{
			while (++j < i)
				mlx_destroy_image(info->mlx, info->xpm_images[j].image);
			exit_image_error(info);
		}
	}
	q = -1;
	while (++q < 5)
		mlx_destroy_image(info->mlx, info->xpm_images[q].image);
	return (1);
}

void	initialize_img(t_info *info)
{
	if (validate_xpm(info))
	{
		info->xpm_wall.image = mlx_xpm_file_to_image(info->mlx, \
		"./image/wall.xpm", &info->xpm_wall.img_width, \
		&info->xpm_wall.img_height);
		info->xpm_back.image = mlx_xpm_file_to_image(info->mlx, \
		"./image/back.xpm", &info->xpm_back.img_width, \
		&info->xpm_back.img_height);
		info->xpm_player.image = mlx_xpm_file_to_image(info->mlx, \
		"./image/player.xpm", &info->xpm_player.img_width, \
		&info->xpm_player.img_height);
		info->xpm_item.image = mlx_xpm_file_to_image(info->mlx, \
		"./image/item.xpm", &info->xpm_item.img_width, \
		&info->xpm_item.img_height);
		info->xpm_exit.image = mlx_xpm_file_to_image(info->mlx, \
		"./image/exit.xpm", &info->xpm_exit.img_width, \
		&info->xpm_exit.img_height);
	}
}

void	draw_image(t_info *info, void *image, int j, int i)
{
	mlx_put_image_to_window(info->mlx, info->window, image, 50 * j, 50 * i);
}

void	create_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '1')
				draw_image(info, info->xpm_wall.image, j, i);
			else if (info->map[i][j] == '0')
				draw_image(info, info->xpm_back.image, j, i);
			else if (info->map[i][j] == 'P')
				draw_image(info, info->xpm_player.image, j, i);
			else if (info->map[i][j] == 'C')
				draw_image(info, info->xpm_item.image, j, i);
			else if (info->map[i][j] == 'E')
				draw_image(info, info->xpm_exit.image, j, i);
			j++;
		}
		i++;
	}
}
