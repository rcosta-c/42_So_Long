/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:19 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:21 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_data *vars)
{
	int		x;
	int		y;
	int		end_x;
	int		end_y;

	x = 0;
	y = 0;
	end_x = vars->map_lines;
	end_y = vars->map_len - 1;
	while (x <= end_x || y <= end_y)
	{
		if (vars->map[x][0] != '1' || vars->map[0][y] != '1'
			|| vars->map[end_x][y] != '1' || vars->map[x][end_y] != '1')
			ft_error("Map doesn't have walls all around", vars);
		else if (x < end_x)
			x++;
		else if (y < end_y)
			y++;
		else
			break ;
	}
}

static void	check_limits(t_data *vars)
{
	if (vars->n_p != 1)
		ft_error("Number of players not correct", vars);
	if (vars->n_e != 1)
		ft_error("Number of exit not correct", vars);
	if (vars->n_c == 0)
		ft_error("Number of Collectibles is 0", vars);
}

static void	found_player(t_data *vars, int x, int y)
{
	vars->n_p++;
	vars->error.x_player = x;
	vars->error.y_player = y;
}

static void	count_elements(t_data *vars)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;

	x = 0;
	end_x = vars->map_lines - 1;
	end_y = vars->map_len - 1;
	while ((x <= end_x || y <= end_y))
	{
		y = 0;
		while (y <= end_y)
		{
			if (vars->map[x][y] == 'P')
				found_player(vars, x, y);
			else if (vars->map[x][y] == 'E')
				vars->n_e++;
			else if (vars->map[x][y] == 'C')
				vars->n_c++;
			else if (strange_dude(vars, x, y))
				ft_error("Strange dude on the map!", vars);
			y++;
		}
		x++;
	}
}

void	check_map(t_data *vars)
{
	validate_maplen(vars);
	check_walls(vars);
	count_elements(vars);
	check_limits(vars);
	flood_map(vars);
}
