/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	measure_lines(t_data *vars, char *map_path)
{
	char	*line;
	int		x_lines;

	x_lines = 0;
	vars->fd = open(map_path, O_RDONLY);
	if (vars->fd < 0)
		ft_error("Error opening the file(map)", vars);
	while (1)
	{
		line = get_next_line(vars->fd);
		if (!line)
		{
			x_lines--;
			free(line);
			break ;
		}
		x_lines++;
		free(line);
	}
	if (x_lines < 1)
		ft_error("Empty map", vars);
	vars->map_lines = x_lines;
	vars->game.x_win = vars->map_lines + 1;
	close(vars->fd);
}
