/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:39:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/06 21:45:51 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(t_structcub *cub)
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
	//if (key == KEY_UP)
	//	key = KEY_W;
	//if (key == KEY_DOWN)
	//	key = KEY_S;
	if (cub->input.l == 1)
		rotation_left(cub);
	if (cub->input.r == 1)
		rotation_right(cub);
	return (0);
}

int		keypress(int key, t_structcub *cub)
{
	if (key == KEY_ESC)
		cub->input.esc = 1;
	if (key == KEY_W || key == KEY_UP)
		cub->input.w = 1;
	if (key == KEY_A)
		cub->input.a = 1;
	if (key == KEY_S || key == KEY_DOWN)
		cub->input.s = 1;
	if (key == KEY_D)
		cub->input.d = 1;
	if (key == KEY_LEFT)
		cub->input.l = 1;
	if (key == KEY_RIGHT)
		cub->input.r = 1;
	return (0);
}

int		keyrelease(int key, t_structcub *cub)
{
	if (key == KEY_ESC)
		cub->input.esc = 0;
	if (key == KEY_W || key == KEY_UP)
		cub->input.w = 0;
	if (key == KEY_A)
		cub->input.a = 0;
	if (key == KEY_S || key == KEY_DOWN)
		cub->input.s = 0;
	if (key == KEY_D)
		cub->input.d = 0;
	if (key == KEY_LEFT)
		cub->input.l = 0;
	if (key == KEY_RIGHT)
		cub->input.r = 0;
	return (0);
}