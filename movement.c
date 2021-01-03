/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:08:55 by cjover-n          #+#    #+#             */
/*   Updated: 2020/12/06 12:59:55 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		vertical_movement(t_structcub *cub)
{
	/*
	if ((cub->map[(int)(cub->pos_x + cub->dir_x * cub->movespeed)][(int)cub->pos_y]) != '1')
		cub->pos_x += cub->dir_x * cub->movespeed;
    if ((cub->map[(int)cub->pos_x][(int)(cub->pos_y + cub->dir_y * cub->movespeed)]) != '1')
		cub->pos_y += cub->dir_y * cub->movespeed;
	*/
	
	if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x * 1)] != '1')
		cub->pos_x += cub->dir_x * cub->movespeed;
	if (cub->map[(int)(cub->pos_y + cub->dir_y * 1)][(int)cub->pos_x] != '1')
		cub->pos_y += cub->dir_y * cub->movespeed;
}

void		horizontal_movement(t_structcub *cub)
{
	if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->plane_x * 1)] != '1')
		cub->pos_x += cub->plane_x * cub->movespeed;
	if (cub->map[(int)(cub->pos_y + cub->plane_y * 1)][(int)cub->pos_x] != '1')
		cub->pos_y += cub->plane_y * cub->movespeed;
}

void		rotation_left(t_structcub *cub)
{
	double dir_y_copy;
	double plane_y_copy;

	dir_y_copy = cub->dir_y;
	cub->dir_y = cub->dir_y * cos(cub->movespeed) - cub->dir_x * sin(cub->movespeed);
	cub->dir_x = dir_y_copy * sin(cub->movespeed) + cub->dir_x * cos(cub->movespeed);
	plane_y_copy = cub->plane_y;
	cub->plane_y = cub->plane_y * cos(cub->movespeed) - cub->plane_x * sin(cub->movespeed);
	cub->plane_x = plane_y_copy * sin(cub->movespeed) + cub->plane_x * cos(cub->movespeed);
}

void		rotation_right(t_structcub *cub)
{
	double dir_y_copy;
	double plane_y_copy;

	dir_y_copy = cub->dir_y;
	cub->dir_y = cub->dir_y * cos(-cub->movespeed) - cub->dir_x * sin(-cub->movespeed);
	cub->dir_x = dir_y_copy * sin(-cub->movespeed) + cub->dir_x * cos(-cub->movespeed);
	plane_y_copy = cub->plane_y;
	cub->plane_y = cub->plane_y * cos(-cub->movespeed) - cub->plane_x * sin(-cub->movespeed);
	cub->plane_x = plane_y_copy * sin(-cub->movespeed) + cub->plane_x * cos(-cub->movespeed);
}