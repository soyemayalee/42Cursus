/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:43:10 by solee2            #+#    #+#             */
/*   Updated: 2023/07/22 02:00:54 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_xpm
{
	void	*image;
	int		img_width;
	int		img_height;
}					t_xpm;

typedef struct s_info
{
	void	*mlx;
	void	*window;
	char	*file;
	int		height;
	int		width;
	char	**map;
	int		player_x;
	int		player_y;
	int		before_x;
	int		before_y;
	int		moves;
	int		item;
	int		exit;
	int		players;
	t_xpm	xpm_back;
	t_xpm	xpm_wall;
	t_xpm	xpm_player;
	t_xpm	xpm_item;
	t_xpm	xpm_exit;
	t_xpm	xpm_images[5];
}				t_info;

//so_long.c
void	launch_game(t_info *info, char *file);
void	validate_map(t_info *info);
void	set_graphics(t_info *info);

//validate_file.c
void	validate_file(int argc, char *file);

//validate_map.c
int		map_shape(t_info *info);
int		map_content(t_info *info);
int		map_vertical_walls(t_info *info);
int		map_horizontal_walls(t_info *info);
int		map_is_valid(t_info *info);

//launch_game.c
void	initialize_struct(t_info *info, char *file);
void	make_map(t_info *info);
void	parse_map(t_info *info);
int		count_item(t_info *info);
void	initialize_player_position(t_info *info);

//set_graphics.c
int		validate_xpm(t_info *info);
void	initialize_img(t_info *info);
void	create_map(t_info *info);

//key_hook.c
void	print_moves(t_info *info);
int		move_player(t_info *info, int x, int y);
int		key_press(int key, t_info *info);

//free_error.c
void	free_map(t_info *info);
void	free_map_copy(char **map_copy, int max);
void	exit_image_error(t_info *info);
int		close_window(t_info *info);
void	exit_error(char *message);

//flood_fill.c
int		flood_fill(t_info *info);

#endif