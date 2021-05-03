/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:39:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 20:18:51 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_structcub *cub, char line, int i)
{
	cub->pos_x = (double)i + 0.5;
	cub->pos_y = (double)cub->line_counter + 0.5;
	if (line == 'N')
		player_north(cub);
	else if (line == 'E')
		player_east(cub);
	else if (line == 'S')
		player_south(cub);
	else if (line == 'W')
		player_west(cub);
	line = '0';
}

void	player_north(t_structcub *cub)
{
	cub->dir_x = 0;
	cub->dir_y = -1;
	cub->plane_x = 0.66;
	cub->plane_y = 0;
	cub->player.player_north = 1;
	cub->player.player_ok = 1;
	printf("JUGADOR MIRANDO PAL NORTE\n");
}

void	player_east(t_structcub *cub)
{
	cub->dir_x = 1;
	cub->dir_y = 0;
	cub->plane_x = 0;
	cub->plane_y = 0.66;
	cub->player.player_east = 1;
	cub->player.player_ok = 1;
	printf("JUGADOR MIRANDO PAL ESTE\n");
}

void	player_south(t_structcub *cub)
{
	cub->dir_x = 0;
	cub->dir_y = 1;
	cub->plane_x = -0.66;
	cub->plane_y = 0;
	cub->player.player_south = 1;
	cub->player.player_ok = 1;
	printf("JUGADOR MIRANDO PAL SUR\n");
}

void	player_west(t_structcub *cub)
{
	cub->dir_x = -1;
	cub->dir_y = 0;
	cub->plane_x = 0;
	cub->plane_y = -0.66;
	cub->player.player_west = 1;
	cub->player.player_ok = 1;
	printf("JUGADOR MIRANDO PAL OESTE\n");
}
