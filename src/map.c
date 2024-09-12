/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:33 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:35 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reading(t_data *vars, char *file)
{
	char	*line;
	int		x;

	vars->map_flg = 1;
	x = 0;
	vars->fd = open(file, O_RDONLY);
	if (vars->fd < 0)
		ft_error("Error opening the file(map)", vars);
	while (1)
	{
		line = get_next_line(vars->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		else
		{
			vars->map[x] = ft_strdup(line);
		}
		free(line);
		x++;
	}
	close(vars->fd);
}
