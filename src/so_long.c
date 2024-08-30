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

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_data	vars;
	t_game	game;
	int		a;// para apagar
	
	a = 0;  //PARA apagar
    check_ac(ac);
    check_filename(av[1]);
    bzero(&vars, sizeof(t_data));
	map_reading(&vars, av[1]);
    check_map(&vars);
	read_texture(&game);
	add_texture(&game, &vars);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (vars.map_len * 40), (vars.map_lines * 40), "solong");
   
	mlx_loop(game.mlx);
/*
		while(vars.map[a])
		{
			ft_printf("%s", vars.map[a]);
			a++;
		}
		ft_printf("\n number of players in the map: 	%d\n", vars.n_p);
		ft_printf("Players: %d, Collectables: %d, Exit: %d, Numb of lines: %d, Numb of Colluns: %d", vars.n_p, vars.n_c, vars.n_e, vars.map_lines, vars.map_len);
*/		return (0);
}
