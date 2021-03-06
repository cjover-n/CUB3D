/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:25:25 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/13 23:20:08 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_check(t_structcub *cub, int posy, int posx)
{
	if (posx < cub->map_len && posy < cub->line_counter)
	{
		if ((cub->map[posy][posx] > '2' || cub->map[posy][posx] < '0')
			&& cub->map[posy][posx] != 33 && cub->map[posy][posx] != '?')
			return (1);
		else if (cub->map[posy][posx] == 33 || cub->map[posy][posx] == '?')
		{
			if (cub->map[posy][posx] == 33)
				cub->map[posy][posx] = '0';
			else
				cub->map[posy][posx] = '2';
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
