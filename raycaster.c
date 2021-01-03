/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 07:01:42 by cjover-n          #+#    #+#             */
/*   Updated: 2021/01/03 11:52:33 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_parameters(t_structcub *cub)
{
    cub->pos_x = 1;
    cub->pos_y = 6;
    cub->dir_x = 1;
    cub->dir_y = 0;
    cub->plane_x = 0;
    cub->plane_y = 0.66;
    cub->rotspeed = 0.1;
    cub->movespeed = 0.25;
}

int    raycaster(t_structcub *cub)
{
	cub->x = 0;
	while (cub->x < cub->screen.width)
	{
		cub->camerax = 2 * cub->x / (double)cub->screen.width - 1;
		cub->raydirx = cub->dir_x + cub->plane_x * cub->camerax;
		cub->raydiry = cub->dir_y + cub->plane_y * cub->camerax;
		cub->map_x = (int)cub->pos_x;
		cub->map_y = (int)cub->pos_y;
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
		//meter aquí función de texturas. Antes que todo esto, gestionar las imágenes primero con función de minilibx de xpm_to_window y luego hacer get_data_addr
		if (cub->side == 0 && cub->raydirx > 0)
			cub->color = RED;
		else if (cub->side == 0 && cub->raydirx < 0)
			cub->color = BLUE;
		else if (cub->side == 1 && cub->raydiry > 0)
			cub->color = GREEN;
		else if (cub->side == 1 && cub->raydiry < 0)
			cub->color = YELLOW;
		cub->start_copy = cub->draw_start;
		cub->end_copy = cub->draw_end;
		while (cub->start_copy < cub->draw_end)
			cub->screen.addr_img[cub->start_copy++ * cub->screen.width + cub->x] = cub->color;//importante: y * w + x
		/*Todo este último while, de cara a cambiar color por textura, se cambia por este fragmento de código de Lode:
		for(int y = drawStart; y<drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
	  */
		while (cub->side < cub->draw_start)
			cub->screen.addr_img[cub->side++ * cub->screen.width + cub->x] = cub->c_hex;
		cub->side = cub->end_copy;
		while (cub->side < cub->screen.height)
			cub->screen.addr_img[cub->side++ * cub->screen.width + cub->x] = cub->f_hex;
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