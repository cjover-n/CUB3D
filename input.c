/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:39:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:28:52 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhandle(t_structcub *cub)
{
	mlx_do_key_autorepeatoff(cub->screen.mlx_ptr);
	mlx_hook(cub->screen.win_ptr, 2, 1L << 0, keypress, cub);
	mlx_hook(cub->screen.win_ptr, 3, 1L << 1, keyrelease, cub);
	mlx_hook(cub->screen.win_ptr, 17, 0, destroy_and_exit, cub);
}

int	keypress(int key, t_structcub *cub)
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

int	keyrelease(int key, t_structcub *cub)
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
