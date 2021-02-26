/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/26 07:27:10 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite(t_structcub *cub)
{
	while (cub->sprite.i < cub->sprite.found)
	{
		cub->sprite.order[cub->sprite.i] = cub->sprite.i;
		cub->sprite.dist[cub->sprite.i] = ((cub->pos_x - sprite[i].x) * (cub->pos_x - sprite[i].x) + (cub->pos_y - sprite[i].y) * (cub->pos_y - sprite[i].y));
	}
}

// void sortsprites(t_structcub *cub)
// {
// 	while (cub->sprite.i < cub->sprite.found)
// 	{
// 		cub->sprite.array[cub->sprite.i];
// 	}
// }
