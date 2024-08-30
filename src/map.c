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

int     ft_map_len(char *line)
{
    int x;

    x = 0;
    while(line[x] != '\0')
        x++;
    if(line[x - 1] == '\n')
        x--;
    return(x);
}

static int    read_map_lines(t_data *vars, char *line)
{
	char	**temp_map;
	int		i;

	if (!line)
		return (0);
	i = 0;
	vars->map_lines++;
	temp_map = (char **)malloc(sizeof(char *) * (vars->map_lines + 1));
	temp_map[vars->map_lines] = NULL;
	while (i < vars->map_lines - 1)
	{
		temp_map[i] = vars->map[i];
		i++;
	}
	temp_map[i] = line;
	if (vars->map)
		free(vars->map);
	vars->map = temp_map;
	return (1);
}

void    map_reading(t_data *vars, char *file)
{
    char    *line;

    vars->fd = open(file, O_RDONLY);
    if (vars->fd < 0)
    {
        ft_error("Error opening the file(map)");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        line = get_next_line(vars->fd);
        if (!read_map_lines(vars, line))
            break;
    }
    close(vars->fd);
    vars->map_len = ft_map_len(vars->map[0]);
}
