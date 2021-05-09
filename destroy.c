/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:13:47 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/09 20:14:09 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		destroy_and_exit(t_structcub *cub)
{
	(void)cub;
	//free_things(cub);
	system("leaks cub3D");
	exit(0);
}
void	free_things(t_structcub *cub)
{
	mlx_destroy_image(cub->screen.mlx_ptr, cub->screen.buffer_img);
	mlx_destroy_window(cub->screen.mlx_ptr, cub->screen.win_ptr);
	free(cub->spr.zbuffer);
	if (cub->spr.found)
	{
		free(cub->spr.x);
		free(cub->spr.y);
		free(cub->spr.spriteorder);
	}
}
