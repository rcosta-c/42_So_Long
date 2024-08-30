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

void    read_texture(t_game *game)
{
    int     a;
    int     b;

    game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &a, &b);
    game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &a, &b);
    game->walls = mlx_xpm_file_to_image(game->mlx, "images/walls.xpm", &a, &b);
    game->floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &a, &b);
    game->collect = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm", &a, &b);
}

//daqui para baixo tenho de alterar
static void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->player, width * 40, height * 40);
	game->y_pos = height;
	game->x_pos = width;
}

static void	place_collectible(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->collect, width * 40, height * 40);
	game->collect++;
}
//alterar ate aqui, esta duas funcoes de cima!!!!


//alterar esta funcao toda//
void    add_texture(t_game *game, t_data *vars)
{
	int	height;
	int	width;

	game->collect = 0;
	height = 0;
	while (height < vars->map_lines)
	{
		width = 0;
		while (vars->map[height][width])
		{
			if (vars->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->walls, width * 40, height * 40);
			if (vars->map[height][width] == 'C')
				place_collectible(game, height, width);
			if (vars->map[height][width] == 'P')
				place_player(game, height, width);
			if (vars->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->win, game->exit, width * 40, height * 40);
			if (vars->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx,
					game->win, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}
