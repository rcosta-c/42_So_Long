/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	validate_flood(t_data *vars)
{
	if (vars->error.find_c != vars->n_c
		|| vars->error.find_e != vars->n_e
		|| vars->error.find_p != vars->n_p
		|| vars->error.find_t != vars->n_t)
		ft_error("There is no valid path in map", vars);
}

static void	copy_map(t_data *vars)
{
	int	x;

	x = 0;
	vars->error.temp_map = ft_calloc(vars->map_lines + 2, sizeof(char *));
	if (!vars->error.temp_map)
		ft_error("Error allocating temp map(flood)", vars);
	while (x <= vars->map_lines)
	{
		vars->error.temp_map[x] = ft_strdup(vars->map[x]);
		if (!vars->error.temp_map)
			ft_error("Error opening the file(map)", vars);
		x++;
	}
	vars->error.temp_flg = 1;
}

static int	map_flood(t_data *vars, int x, int y, char **map)
{
	if (map[x][y] == 'C')
		vars->error.find_c++;
	if (map[x][y] == 'T')
		vars->error.find_t++;
	if (map[x][y] == 'P')
		vars->error.find_p++;
	if (map[x][y] == 'E')
		vars->error.find_e++;
	if (vars->error.x_player < 0 || vars->error.y_player < 0)
		return (0);
	if (vars->error.x_player >= vars->map_lines
		|| vars->error.y_player >= vars->map_len)
		return (0);
	if (map[x][y] != '0' && map[x][y] != 'C'
		&& map[x][y] != 'P' && map[x][y] != 'E'
		&& map[x][y] != 'T')
		return (0);
	map[x][y] = 'F';
	map_flood(vars, x + 1, y, map);
	map_flood(vars, x - 1, y, map);
	map_flood(vars, x, y + 1, map);
	map_flood(vars, x, y - 1, map);
	return (0);
}

void	flood_map(t_data *vars)
{
	copy_map(vars);
	map_flood(vars, vars->error.x_player, \
	vars->error.y_player, vars->error.temp_map);
	validate_flood(vars);
}
