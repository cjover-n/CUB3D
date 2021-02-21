/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 07:01:42 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/21 19:16:11 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_parameters(t_structcub *cub)
{
    cub->rotspeed = 0.1;
    cub->movespeed = 0.30;
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
		step(cub);
		hit_checker(cub);
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
		textures(cub);
		//cub->sprite.zbuffer[cub->x] = cub->perpwalldist;
		sprite(cub);
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

void	hit_checker(t_structcub *cub)
{
	cub->hit = 0;
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

}
