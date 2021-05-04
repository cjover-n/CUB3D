/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:13:47 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/04 20:41:41 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_and_exit(t_structcub *cub)
{
	cub++;
	//iwanttobreakfree(cub);
	system("leaks cub3D");
	exit(0);
}

void	iwanttobreakfree(t_structcub *cub)
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

int	buttonclose(t_structcub *cub)
{
	cub++;
	//iwanttobreakfree(cub);
	system("leaks cub3D");
	exit (0);
	return (0);
}
