/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:39:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/01/03 11:20:14 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_structcub *cub, char line, t_errors *error)
{
	(void)error;
	if (line == 'N')
	{
		//player_north(cub, x);
		cub->player.player_north = 1;
		cub->player.player_ok = 1;
	}
	else if (line == 'E')
	{
		cub->player.player_east = 1;
		cub->player.player_ok = 1;
	}
	else if (line == 'S')
	{
		cub->player.player_south = 1;
		cub->player.player_ok = 1;
	}
	else if (line == 'W')
	{
		cub->player.player_west = 1;
		cub->player.player_ok = 1;
	}
}
/*
void	player_north(t_structcub *cub, int x)
{
	
}
*/