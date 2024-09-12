/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:04 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:07 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ac(int ac)
{
	if (ac < 2)
	{
		ft_printf("Error\n\nHello???Map is missing...!\n\n");
		exit (EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		ft_printf("Error\n\nChoose only 1 map!!\n\n");
		exit (EXIT_FAILURE);
	}
}

void	check_filename(char *filename)
{
	int		x;
	int		z;
	char	*ext;

	x = ft_strlen(filename) - 4;
	z = 0;
	ext = ".ber";
	while (filename[x])
	{
		if (filename[x] == ext[z])
		{
			x++;
			z++;
		}
		else
		{
			ft_printf("Error\n\ncheck if map extension is <.ber>\n\n");
			exit (EXIT_FAILURE);
		}
	}
}

int	strange_dude(t_data *vars, int x, int y)
{
	if (vars->map[x][y] != '1' && vars->map[x][y] != 'C'
		&& vars->map[x][y] != 'P' && vars->map[x][y] != 'E'
		&& vars->map[x][y] != '0')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_map_len(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
		x++;
	if (line[x - 1] == '\n')
		x--;
	return (x);
}
