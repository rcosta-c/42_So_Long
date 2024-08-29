#include "so_long.h"

int    check_filename(char *filename)
{
    int     x;
    int     z;
    char    *ext;
    
    x = ft_strlen(filename) - 4;
    z = 0;
    ext = ".ber";
    while(filename[x])
    {
        if(filename[x] == ext[z])
        {
            x++;
            z++;
        }
        else
        {
        ft_error("check if map extension is <.ber>");
        exit(EXIT_FAILURE);
        } 
    }
    return(0);
}