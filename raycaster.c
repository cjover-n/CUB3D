//Acordarme de poner el header de 42

#include "cub3d.h"

void    init_parameters(t_structcub *cub)
{
    cub->pos_x = 22;
    cub->pos_y = 12;
    cub->dir_x = -1;
    cub->dir_y = 0;
    cub->plane_x = 0;
    cub->plane_y = 0.66;
    cub->rotspeed = 0.1;
    cub->movespeed = 0.25;
}
/*
void    lode_stuff_begining(t_structcub *cub)
{
    int     x;

	
}
*/