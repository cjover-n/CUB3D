/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:44:48 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/07 17:57:32 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		movement(t_structcub *cub)
{
	if (cub->input.esc == 1)
		destroy_and_exit(cub);
	if (cub->input.w == 1)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x *
		cub->movespeed)] != '1')
			cub->pos_x += cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->dir_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->dir_y * cub->movespeed;
	}
	if (cub->input.a == 1)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x -
		cub->plane_x * cub->movespeed)] != '1')
			cub->pos_x -= cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y - cub->plane_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->plane_y * cub->movespeed;
	}
	if (cub->input.s == 1)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x -
		cub->dir_x * cub->movespeed)] != '1')
			cub->pos_x -= cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y - cub->dir_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->dir_y * cub->movespeed;
	}
	if (cub->input.d == 1)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x +
		cub->plane_x * cub->movespeed)] != '1')
			cub->pos_x += cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->plane_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->plane_y * cub->movespeed;
	}
	if (cub->input.l == 1)
		rotation_left(cub);
	if (cub->input.r == 1)
		rotation_right(cub);
	return (0);
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
