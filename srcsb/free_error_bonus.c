/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:13 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:03:02 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	info->map = NULL;
}

void	free_map_copy(char **map_copy, int max)
{
	while (max >= 0)
	{
		free(map_copy[max]);
		max--;
	}
	free(map_copy);
	map_copy = NULL;
}

void	exit_image_error(t_info *info)
{
	mlx_clear_window(info->mlx, info->window);
	mlx_destroy_window(info->mlx, info->window);
	mlx_destroy_display(info->mlx);
	free_map(info);
	free(info->mlx);
	info->mlx = NULL;
	exit_error("ERROR - Image File Failure");
}

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->xpm_back.image);
	mlx_destroy_image(info->mlx, info->xpm_wall.image);
	mlx_destroy_image(info->mlx, info->xpm_player.image);
	mlx_destroy_image(info->mlx, info->xpm_item.image);
	mlx_destroy_image(info->mlx, info->xpm_exit.image);
	mlx_clear_window(info->mlx, info->window);
	mlx_destroy_window(info->mlx, info->window);
	mlx_destroy_display(info->mlx);
	free_map(info);
	free(info->mlx);
	info->mlx = NULL;
	exit(0);
}

void	exit_error(char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
