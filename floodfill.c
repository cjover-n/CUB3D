/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:25:25 by cjover-n          #+#    #+#             */
/*   Updated: 2021/01/31 20:42:10 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floodfill(t_structcub *cub, int posy, int posx)
{
	(void)posy;
	(void)posx;
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
