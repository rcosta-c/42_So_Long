int main(int ac, char **av)
{
	t_data	vars;
	int x;
	char	*map;
	char	**mapx;
	int	fd;
	
    check_ac(ac);
    check_filename(av[1]);
    bzero(&error, sizeof(t_data));
	map_reading(&error, av[1]);
    check_map(&vars);
    /*
	else
	{
		//bzero(&error, sizeof(t_data));
		x = 0;
		(void)ac;	 
		fd = open(av[1], O_RDONLY);
		if (!fd)
			return(1);
		while(x < GNL_CALL)
		{
			map = get_next_line(fd);
			mapx[x] = map;
			if(!map)
				break;
			check_map(mapx[x], &error);
	                check_line(mapx[x], error, x);
			if(THEN_DIFF)
					printf("%s\n", mapx[x]);
			else
				printf("line [%02d]: %s", x, map);
			//free(map);
			x++;
		} */
		printf("%d\n", vars.n_w);
		printf("number of players in the map: 	%d\n", vars.n_p);
		printf("Players: %d, Collectables: %d, Exit: %d, Numb of lines: %d, Numb of Colluns: %d", vars.n_p, vars.n_c, vars.n_e, vars.map_lines, vars.map_len);
		//close(fd);
		return (0);
	}
}
