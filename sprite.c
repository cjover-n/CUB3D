/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/27 00:26:59 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite(t_structcub *cub)
{
	int i = 0;
	while (cub->sprite.i < cub->sprite.found)
	{
		cub->sprite.spriteOrder[cub->sprite.i] = cub->sprite.i;
		cub->sprite.spriteDistance[cub->sprite.i] = ((cub->pos_x - cub->sprite[i].x) * (cub->pos_x - cub->sprite[i].x) + (cub->pos_y - cub->sprite[i].y) * (cub->pos_y - cub->sprite[i].y));
	}
}

// void sortsprites(t_structcub *cub)
// {
// 	while (cub->sprite.i < cub->sprite.found)
// 	{
// 		cub->sprite.array[cub->sprite.i];
// 	}
// }
