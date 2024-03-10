/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:04 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 00:24:56 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(t_info *info, char *file)
{
	initialize_struct(info, file);
	make_map(info);
	parse_map(info);
	count_item(info);
	initialize_player_position(info);
}

void	validate_map(t_info *info)
{
	if (map_is_valid(info) == 0)
	{
		free_map(info);
		exit_error("ERROR - Map is Not Valid");
	}
}

void	set_graphics(t_info *info)
{
	int	width;
	int	height;

	width = info->width;
	height = info->height;
	info->window = mlx_new_window(info->mlx, \
	50 * width, 50 * height, "so_long");
	if (!info->window)
		exit_error("ERROR - Window Pointer Error");
	initialize_img(info);
	create_map(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	validate_file(argc, argv[1]);
	launch_game(&info, argv[1]);
	validate_map(&info);
	info.mlx = mlx_init();
	if (!info.mlx)
		exit_error("ERROR - MLX POINTER ERROR\n");
	set_graphics(&info);
	mlx_key_hook(info.window, &key_press, &info);
	mlx_hook(info.window, 17, 0, close_window, &info);
	mlx_loop(info.mlx);
}
