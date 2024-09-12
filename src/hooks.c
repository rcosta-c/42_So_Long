/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:01:23 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/09/03 11:01:38 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_data *vars)
{
	int	i;
	int	j;
	int	k;

	i = vars->game.x_pos;
	j = (vars->game.y_pos) + 1;
	if (vars->map[j][i] == '1')
		return (0);
	k = validate_move(vars, i, j);
	if (!k)
		return (0);
	vars->map[j - 1][i] = validate_left(vars);
	message_after(vars->game.counter);
	return (1);
}

static int	move_down(t_data *vars)
{
	int	i;
	int	j;
	int	k;

	i = vars->game.x_pos;
	j = (vars->game.y_pos) - 1;
	if (vars->map[j][i] == '1')
		return (0);
	k = validate_move(vars, i, j);
	if (!k)
		return (0);
	vars->map[j + 1][i] = validate_left(vars);
	message_after(vars->game.counter);
	return (1);
}

static int	move_left(t_data *vars)
{
	int	i;
	int	j;
	int	k;

	i = (vars->game.x_pos) - 1;
	j = vars->game.y_pos;
	if (vars->map[j][i] == '1')
		return (0);
	k = validate_move(vars, i, j);
	if (!k)
		return (0);
	vars->map[j][i + 1] = validate_left(vars);
	message_after(vars->game.counter);
	return (1);
}

static int	move_right(t_data *vars)
{
	int	i;
	int	j;
	int	k;

	i = (vars->game.x_pos) + 1;
	j = vars->game.y_pos;
	if (vars->map[j][i] == '1')
		return (0);
	k = validate_move(vars, i, j);
	if (!k)
		return (0);
	vars->map[j][i - 1] = validate_left(vars);
	message_after(vars->game.counter);
	return (1);
}

int	ft_hooks(int command, t_data *vars)
{
	int	works;

	if (command == 65307)
		to_the_exit(vars);
	if (command == 119 || command == 87)
		works = move_down(vars);
	if (command == 115 || command == 83)
		works = move_up(vars);
	if (command == 97 || command == 65)
		works = move_left(vars);
	if (command == 100 || command == 68)
		works = move_right(vars);
	if (command != 119 && command != 87 \
		&& command != 115 && command != 83 && command != 97 \
		&& command != 65 && command != 100 && command != 68)
		works = 0;
	if (works)
		add_texture(vars);
	return (1);
}
