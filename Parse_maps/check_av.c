#include "so_long.h"

void    check_ac(int ac)
{
    if (ac < 2)
	{
		ft_error("Hello???Map is missing...!");
		exit(EXIT_FAILURE);	
	}
	else if (ac > 2)
	{
		ft_error("Choose only 1 map!!");
		exit(EXIT_FAILURE);
	}
}