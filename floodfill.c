/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:25:25 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/23 01:03:16 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_check(t_structcub *cub, int posy, int posx)
{
	if (posx < cub->map_len && posy < cub->line_counter)
	{
		if ((cub->map[posy][posx] > '2' || cub->map[posy][posx] < '0')
			&& cub->map[posy][posx] != 33)
			return (1);
		else if (cub->map[posy][posx] == 33)
		{
			cub->map[posy][posx] = '0';
			if (flood_check(cub, posy + 1, posx) == 1)
				return (1);
			if (flood_check(cub, posy, posx + 1) == 1)
				return (1);
			if (posy == 0 || posx == 0)
				return (1);
			if (flood_check(cub, posy - 1, posx) == 1)
				return (1);
			if (flood_check(cub, posy, posx - 1) == 1)
				return (1);
		}
		return (0);
	}
	return (1);
}
