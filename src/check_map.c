/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:24:19 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/30 11:24:21 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_data *vars)
{
	int		x = 0;
	int		y = 0;
	int		end_x;
	int		end_y;

	end_x = vars->map_lines - 1;
	end_y = vars->map_len - 1;
	//printf("%d, %d, %d, %d\n", x, y, end_x, end_y);
	while(x <= end_x || y <= end_y)
	{
	//	printf("x=%d, y=%d\n", x, y);
		if (vars->map[x][0] != '1' || vars->map[0][y] != '1' || vars->map[end_x][y] != '1' || vars->map[x][end_y] != '1')
				{
					ft_error("Map doesn't have walls all around");
					exit(EXIT_FAILURE);
				}  
		else if (x < end_x)
			x++;
		else if (y < end_y)
			y++;
		else
			break;
	}
}

static void	check_rect(t_data *vars)
{
	int x;
	int	cmp1;
	int	cmp2;

	x = 0;
	while(vars->map[x + 1])
	{
		cmp1 = ft_strlen(vars->map[x]);
		cmp2 = ft_strlen(vars->map[x + 1]);
		if(cmp1 == cmp2)
		{
			x++;
		}
		else
		{
			ft_error("Map not rectangular");
			exit(EXIT_FAILURE);
		}
	}
}

static void	check_limits(t_data *vars)
{
	if(vars->n_p > 1)
	{
		ft_error("Number of players more than 1.");
		exit(EXIT_FAILURE);
	}
	else if (vars->n_e > 1)
	{
		ft_error("Number of exit more than 1");
		exit(EXIT_FAILURE);
	}
	else if (vars->n_c == 0)
	{
		ft_error("Number of Collectibles is 0");
		exit(EXIT_FAILURE);
	}
}

void	check_around(t_data *vars, int x, int y)
{
	if (vars->map[x + 1][y] == '1' && vars->map[x - 1][y] == '1' && vars->map[x][y + 1] == '1' && vars->map[x][y - 1] == '1')
	{
		if (vars->map[x][y] == 'P')
		{
			ft_error("Player is surrounded by walls");
			exit(EXIT_FAILURE);
		}
		else if (vars->map[x][y] == 'E')
		{	
			ft_error("Exit is surrounded by walls");
			exit(EXIT_FAILURE);
		}
		else if (vars->map[x][y] == 'C')
		{
			ft_error("Collectible is surrounded by walls");
			exit(EXIT_FAILURE);
		}
	}

}

static int	strange_dude(t_data *vars, int x, int y)
{
	if (vars->map[x][y] != '1' && vars->map[x][y] != 'C' && vars->map[x][y] != 'P' && vars->map[x][y] != 'E' && vars->map[x][y] != '0')
	{
		return(1); //VER SE ESTA BEM
	}
	else
		return (0);
}

void	check_map (t_data *vars)
{
	int	x = 0;
	int	y = 0;
	int	end_x;
	int	end_y;

	end_x = vars->map_lines - 1;
	end_y = vars->map_len - 1;
	check_rect(vars);
	check_walls(vars);
	//printf("%d, %d, %d, %d\n", x, y, end_x, end_y);

	while((x <= end_x || y <= end_y))
	{
	//	printf("touaqui %d ,%d\n", x, y);
		if(vars->map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
		else if (vars->map[x][y] == 'P')
		{
			check_around(vars, x, y);
			vars->n_p++;
		}
		else if (vars->map[x][y] == 'E')
		{
			check_around(vars, x, y);
			vars->n_e++;
		}
		else if (vars->map[x][y] == 'C')
		{
			check_around(vars, x, y);
			vars->n_c++;
		}
		else if (vars->map[x][y] == '1')
			vars->n_w++;
		else if (strange_dude(vars, x, y))
		{
			ft_error("Strange dude on the map!");
			exit(EXIT_FAILURE);
		}
		if(x > end_x)
			break;
		y++;
	}
	check_limits(vars);

	//printf("sai\n");
}
	


