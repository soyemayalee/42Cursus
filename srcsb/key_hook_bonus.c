/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:38 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 01:58:25 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_info *info)
{
	char	*moves;

	info->moves = info->moves + 1;
	moves = ft_itoa(info->moves);
	ft_putstr_fd("Movements: ", 1);
	ft_putstr_fd(moves, 1);
	ft_putstr_fd("\n", 1);
	free(moves);
}

void	display_moves(t_info *info)
{
	char	*moves;

	moves = ft_itoa(info->moves);
	mlx_put_image_to_window(info->mlx, info->window, info->xpm_wall.image, \
	0, 50 * (info->height - 1));
	mlx_put_image_to_window(info->mlx, info->window, info->xpm_wall.image, \
	50, 50 * (info->height - 1));
	mlx_string_put(info->mlx, info->window, 10, info->height * 50 - 10, \
	0xff2d00, "Moves: ");
	mlx_string_put(info->mlx, info->window, 65, info->height * 50 - 10, \
	0xff2d00, moves);
	free(moves);
}

int	move_player(t_info *info, int x, int y)
{
	if (info->item == 0 && info->map[y][x] == 'E')
		close_window(info);
	else if (info->map[y][x] == '1' || info->map[y][x] == 'E')
		return (0);
	info->player_x = x;
	info->player_y = y;
	if (info->map[y][x] == 'C')
	{
		info->map[y][x] = '0';
		info->item = info->item - 1;
	}
	return (1);
}

int	key_press(int key, t_info *info)
{
	int	flag;

	flag = 0;
	info->before_x = info->player_x;
	info->before_y = info->player_y;
	if (key == UP)
		flag = move_player(info, info->before_x, info->before_y - 1);
	else if (key == DOWN)
		flag = move_player(info, info->before_x, info->before_y + 1);
	else if (key == LEFT)
		flag = move_player(info, info->before_x - 1, info->before_y);
	else if (key == RIGHT)
		flag = move_player(info, info->before_x + 1, info->before_y);
	else if (key == ESC)
		close_window(info);
	if (flag == 1)
	{
		mlx_put_image_to_window(info->mlx, info->window, \
		info->xpm_player.image, 50 * info->player_x, 50 * info->player_y);
		mlx_put_image_to_window(info->mlx, info->window, \
		info->xpm_back.image, 50 * info->before_x, 50 * info->before_y);
		print_moves(info);
		display_moves(info);
	}
	return (0);
}
