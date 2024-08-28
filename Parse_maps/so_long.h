#include "include/gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
//#define GNL_CALL 10000
//#define THEN_DIFF 1

typedef struct	s_data {
	int	n_p;
	int	n_c;
	int	n_e;
	int	n_w;
	//int	min_walls;
	
	int	map_len;
	char	**map;
	int		fd;
	int	map_lines;
}			t_data;
