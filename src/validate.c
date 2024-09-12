/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_maplen(t_data *vars)
{
	int	x;

	x = 0;
	while (x <= ((vars->map_lines) - 1))
	{
		if (ft_map_len(vars->map[x]) != ft_map_len(vars->map[x + 1]))
			ft_error("Map not rectangular(lines not the same lenght)", vars);
		else
			x++;
	}
	vars->map_len = ft_map_len(vars->map[x - 1]);
	vars->game.y_win = vars->map_len;
}

char	validate_left(t_data *vars)
{
	char	res;

	if (vars->game.exit_flg == 2)
	{
		vars->game.exit_flg--;
		res = '0';
		ft_printf("You need to collect them all\n");
		return (res);
	}
	if (vars->game.exit_flg == 1)
	{
		vars->game.exit_flg--;
		res = 'E';
		return (res);
	}
	else
	{
		res = '0';
		return (res);
	}
}

int	validate_exit(t_data *vars, int x, int y)
{
	if (vars->n_c > 0)
	{
		vars->game.exit_flg = 2;
		vars->map[x][y] = 'P';
		vars->game.x_pos = x;
		vars->game.y_pos = y;
		vars->game.counter++;
		return (0);
	}
	else
	{
		ft_printf("\n\n You have done it!!! Finally,!!\n\n");
		to_the_exit(vars);
	}
	return (1);
}

int	validate_move(t_data *vars, int y, int x)
{
	if (vars->map[x][y] == 'E')
		validate_exit(vars, x, y);
	if (vars->map[x][y] == '0')
	{
		vars->map[x][y] = 'P';
		vars->game.x_pos = x;
		vars->game.y_pos = y;
		vars->game.counter++;
	}
	if (vars->map[x][y] == 'C')
	{
		vars->map[x][y] = 'P';
		vars->game.x_pos = x;
		vars->game.y_pos = y;
		vars->n_c--;
		vars->game.counter++;
		message_collected(vars->n_c);
	}
	return (1);
}
