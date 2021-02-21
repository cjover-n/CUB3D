/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:44:48 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/21 19:13:56 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		vertical_movement(t_structcub *cub)
{
	if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x * cub->movespeed)] != '1')
		cub->pos_x += cub->dir_x * cub->movespeed;
	if (cub->map[(int)(cub->pos_y + cub->dir_y * cub->movespeed)][(int)cub->pos_x] != '1')
		cub->pos_y += cub->dir_y * cub->movespeed;
}

void		horizontal_movement(t_structcub *cub)
{
	if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->plane_x * cub->movespeed)] != '1')
		cub->pos_x += cub->plane_x * cub->movespeed;
	if (cub->map[(int)(cub->pos_y + cub->plane_y * cub->movespeed)][(int)cub->pos_x] != '1')
		cub->pos_y += cub->plane_y * cub->movespeed;
}

void		rotation_left(t_structcub *cub)
{
	double dir_y_copy;
	double plane_y_copy;

	dir_y_copy = cub->dir_y;
	cub->dir_y = cub->dir_y * cos(cub->movespeed) -
		cub->dir_x * sin(cub->movespeed);
	cub->dir_x = dir_y_copy * sin(cub->movespeed) +
		cub->dir_x * cos(cub->movespeed);
	plane_y_copy = cub->plane_y;
	cub->plane_y = cub->plane_y * cos(cub->movespeed) -
		cub->plane_x * sin(cub->movespeed);
	cub->plane_x = plane_y_copy * sin(cub->movespeed) +
		cub->plane_x * cos(cub->movespeed);
}

void		rotation_right(t_structcub *cub)
{
	double dir_y_copy;
	double plane_y_copy;

	dir_y_copy = cub->dir_y;
	cub->dir_y = cub->dir_y * cos(-cub->movespeed) -
		cub->dir_x * sin(-cub->movespeed);
	cub->dir_x = dir_y_copy * sin(-cub->movespeed) +
		cub->dir_x * cos(-cub->movespeed);
	plane_y_copy = cub->plane_y;
	cub->plane_y = cub->plane_y * cos(-cub->movespeed) -
		cub->plane_x * sin(-cub->movespeed);
	cub->plane_x = plane_y_copy * sin(-cub->movespeed) +
		cub->plane_x * cos(-cub->movespeed);
}
