/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:28 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:29 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_enemy(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.enemy, width * 40, height * 40);
}

void	read_texture(t_data *vars)
{
	int	a;
	int	b;

	vars->game.player = mlx_xpm_file_to_image(vars->game.mlx,
			"images/player.xpm", &a, &b);
	vars->game.exit = mlx_xpm_file_to_image(vars->game.mlx,
			"images/exit.xpm", &a, &b);
	vars->game.walls = mlx_xpm_file_to_image(vars->game.mlx,
			"images/walls.xpm", &a, &b);
	vars->game.floor = mlx_xpm_file_to_image(vars->game.mlx,
			"images/floor.xpm", &a, &b);
	vars->game.collect = mlx_xpm_file_to_image(vars->game.mlx,
			"images/collectible.xpm", &a, &b);
	vars->game.enemy = mlx_xpm_file_to_image(vars->game.mlx,
			"images/enemy.xpm", &a, &b);
}

static void	put_counter(t_data *vars)
{
	char	*res;

	res = ft_itoa(vars->game.counter);
	mlx_string_put(vars->game.mlx, vars->game.win, 15, 25, 0xFFFFF, res);
	free(res);
}

void	pre_add_texture(t_data	*vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	add_texture(vars, width, height);
}

void	add_texture(t_data *vars, int width, int height)
{
	while (height <= vars->map_lines)
	{
		width = 0;
		while (vars->map[height][width])
		{
			if (vars->map[height][width] == 'T')
				place_enemy(vars, height, width);
			if (vars->map[height][width] == '1')
				place_walls(vars, height, width);
			if (vars->map[height][width] == 'C')
				place_collectible(vars, height, width);
			if (vars->map[height][width] == 'P')
				place_player(vars, height, width);
			if (vars->map[height][width] == 'E')
				place_exit(vars, height, width);
			if (vars->map[height][width] == '0')
				place_floor(vars, height, width);
			width++;
		}
		height++;
	}
	put_counter(vars);
}
