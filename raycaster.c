//Acordarme de poner el header de 42

#include "cub3d.h"

void    init_parameters(t_structcub *cub)
{
    cub->pos_x = 14;
    cub->pos_y = 3;
    cub->dir_x = -1;
    cub->dir_y = 0;
    cub->plane_x = 0;
    cub->plane_y = 0.66;
    cub->rotspeed = 0.1;
    cub->movespeed = 0.25;
}

int    raycaster(t_structcub *cub)
{
	cub->x = 0;
    //img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/pink.xpm", &cub.width, &cub.height);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	while (cub->x < cub->screen.width)
	{
		cub->camerax = 2 * cub->x / (double)cub->screen.width - 1;
		cub->raydirx = cub->dir_x + cub->plane_x * cub->camerax;
		cub->raydiry = cub->dir_y + cub->plane_y * cub->camerax;
		cub->map_x = (int)cub->pos_x;
		cub->map_y = (int)cub->pos_y;
		//cub->deltadist_x = fabs(1 / cub->raydirx);
		//cub->deltadist_y = fabs(1 / cub->raydiry);
		//double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : abs(1 / rayDirX));
      	//double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : abs(1 / rayDirY));
		if (cub->raydiry == 0)
			cub->deltadist_x = 0;
		else if (cub->raydirx == 0)
			cub->deltadist_x = 1;
		else
			cub->deltadist_x = fabs(1 / cub->raydirx);
		if (cub->raydirx == 0)
			cub->deltadist_y = 0;
		else if (cub->raydiry == 0)
			cub->deltadist_y = 1;
		else
			cub->deltadist_y = fabs(1 / cub->raydiry);
		cub->hit = 0;
		step(cub);
		while (cub->hit == 0)
      	{
        	if (cub->sidedist_x < cub->sidedist_y)
        	{
        		cub->sidedist_x += cub->deltadist_x;
          		cub->map_x += cub->step_x;
          		cub->side = 0;
        	}
        	else
        	{
        		cub->sidedist_y += cub->deltadist_y;
        		cub->map_y += cub->step_y;
        		cub->side = 1;
        	}
        	if (cub->map[cub->map_y][cub->map_x] == '1')
				cub->hit = 1;
      	}
		if (cub->side == 0)
			cub->perpwalldist = (cub->map_x - cub->pos_x + (1 - cub->step_x) / 2) / cub->raydirx;
		else
			cub->perpwalldist = (cub->map_y - cub->pos_y + (1 - cub->step_y) / 2) / cub->raydiry;
		cub->lineheight = (int)(cub->screen.height / cub->perpwalldist);
		cub->draw_start = (-1 * cub->lineheight) / 2 + cub->screen.height / 2;
		if (cub->draw_start < 0)
			cub->draw_start = 0;
		cub->draw_end = cub->lineheight / 2 + cub->screen.height / 2;
		if (cub->draw_end >= cub->screen.height)
			cub->draw_end = cub->screen.height - 1;
		if (cub->side == 0 && cub->raydirx > 0)
			cub->color = RED;
		else if (cub->side == 0 && cub->raydirx < 0)
			cub->color = BLUE;
		else if (cub->side == 1 && cub->raydiry > 0)
			cub->color = GREEN;
		else if (cub->side == 1 && cub->raydiry < 0)
			cub->color = YELLOW;
		cub->start_copy = cub->draw_start;
		while (cub->start_copy < cub->draw_end)
			cub->screen.addr_img[cub->start_copy++ * cub->screen.width + cub->x] = cub->color;
		cub->x++;
	}
	mlx_put_image_to_window(cub->screen.mlx_ptr, cub->screen.win_ptr, cub->screen.buffer_img, 0, 0);
	return(0);
}

void	step(t_structcub *cub)
{
	if (cub->raydirx < 0)
      {
        cub->step_x = -1;
        cub->sidedist_x = (cub->pos_x - cub->map_x) * cub->deltadist_x;
      }
      else
      {
        cub->step_x = 1;
        cub->sidedist_x = (cub->map_x + 1.0 - cub->pos_x) * cub->deltadist_x;
      }
      if (cub->raydiry < 0)
      {
        cub->step_y = -1;
        cub->sidedist_y = (cub->pos_y - cub->map_y) * cub->deltadist_y;
      }
      else
      {
        cub->step_y = 1;
        cub->sidedist_y = (cub->map_y + 1.0 - cub->pos_y) * cub->deltadist_y;
      }
}