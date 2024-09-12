/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:10:45 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/09/03 10:10:47 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_player(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.player, width * 40, height * 40);
	vars->game.y_pos = height;
	vars->game.x_pos = width;
}

void	place_collectible(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.collect, width * 40, height * 40);
}

void	place_walls(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.walls, width * 40, height * 40);
}

void	place_exit(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.exit, width * 40, height * 40);
}

void	place_floor(t_data *vars, int height, int width)
{
	mlx_put_image_to_window(vars->game.mlx,
		vars->game.win, vars->game.floor, width * 40, height * 40);
}
