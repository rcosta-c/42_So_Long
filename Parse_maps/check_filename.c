#include "so_long.h"

void    check_filename(char *filename)
{
    int     x;

    x = ft_strlen(*filename);
    if (filename[x - 1] == 'r')
    {
        if (filename[x - 2] == 'e')
        {
            if (filename[x - 3] == 'b')
            {
                if (filename[x - 4] == '.')
                    
            }
        }
    }
    else
    {
        ft_error("check if map extension is <.ber>");
        exit(EXIT_FAILURE);
    }
}