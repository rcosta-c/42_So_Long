#include "so_long.h"

void	check_walls(t_data vars)
{
	int	x;
	int	y;
	while(vars->map[0][y])
	{
		if(vars->map[0][y] != '1')
		{
			ft_error("Map doesn't have walls all around");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	while(vars->map[x][0])
	{
		if(vars->map[x][0] != '1')
		{
			ft_error("Map doesn't have walls all around");
			exit(EXIT_FAILURE);
		}
		x++;
	}
	x = 0;
	while(vars->map[x][vars->map_len])
	{
		if(vars->map[x][vars->map_len] != '1')
		{
			ft_error("Map doesn't have walls all around");
			exit(EXIT_FAILURE);
		}
		x++;
	}
	y = 0;
	while(vars->map[vars->map_lines][y])
	{
		if(vars->map[vars->map_len][y] != '1')
		{
			ft_error("Map doesn't have walls all around");
			exit(EXIT_FAILURE);
		}
		x++;
	}
}
/*
void	check_line(char *line, t_data *error, int counter)
{
	int	x;

	x = strlen(line);
	if(line[x] == '\0')
	{
		x--;
		if(line[x] == '\n')
			x--;
	}
	if(counter == 0)
		error->map_colums = x;
	if (error->map_colums != x)
		ft_error("Map not rectangular!!");
}
*/

void	check_rect(t_data vars)
{
	int	i;
	int	y;
	int	temp;

	x = 0;
	y = 0;
	while(vars->map[x])
	{
		temp = ft_map_len(vars->map[x]);
		x++
		

		
	}
}
void	check_map (t_data vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_rect(vars);
	check_walls(vars);
	while(vars->map[x][y])
	{
		if(vars-map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
		else if (vars-map[x][y] == 'P')
			error->n_p++;
		else if (vars->map[x][y] == 'E')
			error->n_e++;
		else if (vars->map[x][y] == 'C')
			error->n_c++;
		else if (vars->map[x][y] == '1')
			error->n_w++;
		y++;
	}
	


