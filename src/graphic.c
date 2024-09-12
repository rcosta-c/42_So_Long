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

#include "so_long.h"

void	read_texture(t_data *vars)
{
	int	x;
	int	y;

	vars->game.player = mlx_xpm_file_to_image(vars->game.mlx,
			"images/player.xpm", &x, &y);
	vars->game.exit = mlx_xpm_file_to_image(vars->game.mlx,
			"images/exit.xpm", &x, &y);
	vars->game.walls = mlx_xpm_file_to_image(vars->game.mlx,
			"images/walls.xpm", &x, &y);
	vars->game.floor = mlx_xpm_file_to_image(vars->game.mlx,
			"images/floor.xpm", &x, &y);
	vars->game.collect = mlx_xpm_file_to_image(vars->game.mlx,
			"images/collectible.xpm", &x, &y);
}

void	add_texture(t_data *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x <= vars->map_lines)
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '1')
				place_walls(vars, x, y);
			if (vars->map[x][y] == 'C')
				place_collectible(vars, x, y);
			if (vars->map[x][y] == 'P')
				place_player(vars, x, y);
			if (vars->map[x][y] == 'E')
				place_exit(vars, x, y);
			if (vars->map[x][y] == '0')
				place_floor(vars, x, y);
			y++;
		}
		x++;
	}
}
