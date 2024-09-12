/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_flags(t_data *vars)
{
	vars->game.signal = 0;
	vars->map_flg = 0;
	vars->error.temp_flg = 0;
	vars->game.exit_flg = 0;
}

static void	init_mem(t_data *vars)
{
	vars->n_c = 0;
	vars->n_p = 0;
	vars->n_e = 0;
	vars->n_t = 0;
	vars->collected = 0;
	vars->fd = 0;
	vars->map = ft_calloc(vars->map_lines + 2, sizeof(char **));
	vars->game.counter = 0;
	vars->error.find_c = 0;
	vars->error.find_e = 0;
	vars->error.find_p = 0;
	vars->error.find_t = 0;
}

int	main(int ac, char **av)
{
	t_data	vars;
	int		w;
	int		h;

	w = 0;
	h = 0;
	init_flags(&vars);
	check_ac(ac);
	check_filename(av[1]);
	measure_lines(&vars, av[1]);
	init_mem(&vars);
	map_reading(&vars, av[1]);
	check_map(&vars);
	vars.game.signal = 1;
	vars.game.mlx = mlx_init();
	vars.game.win = mlx_new_window(vars.game.mlx,
			(vars.game.y_win * 40), (vars.game.x_win * 40), "solong");
	read_texture(&vars);
	add_texture(&vars, w, h);
	mlx_key_hook(vars.game.win, ft_hooks, &vars);
	mlx_hook(vars.game.win, 17, 0, to_the_exit, &vars);
	mlx_loop(vars.game.mlx);
	return (0);
}
