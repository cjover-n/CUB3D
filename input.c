/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:39:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/27 12:36:13 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_structcub *cub)
{
	if (key == KEY_ESC)
		destroy_and_exit(cub);
	if (key == KEY_W || key == KEY_UP)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x *
		cub->movespeed)] != '1')
			cub->pos_x += cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->dir_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->dir_y * cub->movespeed;
	}
	if (key == KEY_A)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x -
		cub->plane_x * cub->movespeed)] != '1')
			cub->pos_x -= cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y - cub->plane_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->plane_y * cub->movespeed;
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x -
		cub->dir_x * cub->movespeed)] != '1')
			cub->pos_x -= cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y - cub->dir_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->dir_y * cub->movespeed;
	}
	if (key == KEY_D)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x +
		cub->plane_x * cub->movespeed)] != '1')
			cub->pos_x += cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->plane_y *
		cub->movespeed)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->plane_y * cub->movespeed;
	}
	if (key == KEY_UP)
		key = KEY_W;
	if (key == KEY_DOWN)
		key = KEY_S;
	if (key == KEY_LEFT)
		rotation_left(cub);
	if (key == KEY_RIGHT)
		rotation_right(cub);
	return (0);
}
