/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:25:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:25:14 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../mlx/minilibx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>

typedef struct s_check
{
	int		temp_flg;
	char	**temp_map;
	int		x_player;
	int		y_player;
	int		find_p;
	int		find_e;
	int		find_c;
	int		find_t;
}				t_check;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*exit;
	void	*floor;
	void	*walls;
	void	*enemy;
	void	*collect;
	int		signal;
	int		exit_flg;
	int		x_win;
	int		y_win;
	int		x_pos;
	int		y_pos;
	int		end_x;
	int		end_y;
	int		counter;
}				t_game;

typedef struct s_data
{
	int		n_p;
	int		n_c;
	int		n_e;
	int		n_t;
	int		collected;
	int		map_len;
	int		map_flg;
	int		fd;
	int		map_lines;
	char	**map;
	t_game	game;
	t_check	error;
}				t_data;

void	flood_map(t_data *vars);
void	validate_maplen(t_data *vars);
char	validate_left(t_data *vars);
int		validate_move(t_data *vars, int i, int j);
int		validate_exit(t_data *vars, int i, int j);
void	message_collected(int collected);
void	measure_lines(t_data *vars, char *path);
void	message_after(int counter);
int	to_the_exit(t_data *vars);
int		ft_hooks(int command, t_data *vars);
int		strange_dude(t_data *vars, int x, int y);
void	place_floor(t_data *vars, int height, int width);
void	place_exit(t_data *vars, int height, int width);
void	place_walls(t_data *vars, int height, int width);
void	place_player(t_data *vars, int height, int width);
void	place_collectible(t_data *vars, int height, int width);
void	pre_add_texture(t_data	*vars);
void	add_texture(t_data *vars, int width, int height);
void	read_texture(t_data *vars);
void	map_reading(t_data *vars, char *file);
int		ft_map_len(char *line);
void	check_map(t_data *vars);
void	check_filename(char *filename);
void	ft_error(char *message, t_data *vars);
void	check_ac(int ac);
void	place_enemy(t_data *vars, int height, int width);

#endif
