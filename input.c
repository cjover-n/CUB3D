/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:39:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/07 18:04:11 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (key == KEY_T)
		cub->input.t = 1;
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