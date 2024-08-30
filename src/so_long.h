/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:25:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:25:14 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../mlx/minilibx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>

typedef struct	s_data {
	int	n_p;
	int	n_c;
	int	n_e;
	int	n_w;
	int	collected; //esta é nova! falta implementar no codigo.
	int	map_len;
	char	**map;
	int		fd;
	int	map_lines;
}			t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	void	*player;
	void	*exit;
	void	*floor;
	void	*walls;
	void	*collect;
	int		x_pos;
	int		y_pos;
	int		counter;
}			t_game;

void    add_texture(t_game *game, t_data *vars);
void    read_texture(t_game *game);
void    map_reading(t_data *vars, char *file);
int     ft_map_len(char *line);
void	check_map (t_data *vars);
int    check_filename(char *filename);
void	ft_error(char *message);
void    check_ac(int ac);


#endif
