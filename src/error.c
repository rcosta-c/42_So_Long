/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:24 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:26 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mlx(t_data *vars)
{
	mlx_destroy_image(vars->game.mlx, vars->game.exit);
	mlx_destroy_image(vars->game.mlx, vars->game.player);
	mlx_destroy_image(vars->game.mlx, vars->game.walls);
	mlx_destroy_image(vars->game.mlx, vars->game.collect);
	mlx_destroy_image(vars->game.mlx, vars->game.floor);
	mlx_destroy_window(vars->game.mlx, vars->game.win);
	mlx_destroy_display(vars->game.mlx);
	free(vars->game.mlx);
}

int	to_the_exit(t_data *vars)
{
	int	line;

	line = 0;
	if (vars->game.signal == 1)
		destroy_mlx(vars);
	if (vars->error.temp_flg == 1)
	{
		while (line <= vars->map_lines)
			free(vars->error.temp_map[line++]);
		free(vars->error.temp_map);
	}
	line = 0;
	if (vars->map_flg == 1)
	{
		while (line <= vars->map_lines)
			free(vars->map[line++]);
		free(vars->map);
	}
	exit(0);
}

void	ft_error(char *message, t_data *vars)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_printf("\n<< why?where? >>\n<< %s >>\n", message);
	to_the_exit(vars);
}

void	message_after(int counter)
{
	if (counter <= 8)
		ft_printf("Moves done so far :%i\n", counter);
	if (counter >= 9 && counter <= 24)
		ft_printf("Moving a lot... %i\n", counter);
	if (counter >= 25 && counter <= 44)
		ft_printf("Still moving? %i isnt a lot of moves?\n", counter);
	if (counter >= 45)
		ft_printf("????  %i moves and not done?\n", counter);
}

void	message_collected(int collected)
{
	if (collected > 1)
		ft_printf("Still need to collect:%i\n", collected);
	if (collected == 1)
		ft_printf("Just %i collectible is missing!\n", collected);
	if (collected == 0)
		ft_printf("Now, run to the exit!!\n", collected);
}
