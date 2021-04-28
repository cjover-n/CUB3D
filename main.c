/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/28 14:42:08 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_and_exit(t_structcub *cub)
{
	//mlx_destroy_image(cub->screen.mlx_ptr, cub->screen.buffer_img);
	//mlx_destroy_window(cub->screen.mlx_ptr, cub->screen.win_ptr);
	free(cub->spr.zbuffer);
	if (cub->spr.found)
		free(cub->spr.spriteorder);
	exit(0);
}

void	init_parameters(t_structcub *cub)
{
	cub->rotspeed = 0.01;
	cub->movespeed = 0.05;
	cub->buf = 4;
	cub->spr.array = malloc(sizeof(double) * cub->buf);
	if (!(cub->spr.array))
		return ;
}

int	main(int argc, char **argv)
{
	t_structcub		cub;

	ft_bzero(&cub, sizeof(cub));
	init_parameters(&cub);
	if (argc != 2)
		error_handler1(1);
	else
	{
		readmap(argv[1], &cub);
		if (cub.player.player_ok == 0)
			error_handler1(9);
		while (cub.map[cub.map_height] != NULL)
		{
			cub.map_height++;
		}
		messages(&cub);
		cub.screen.mlx_ptr = mlx_init();
		cub.screen.win_ptr = mlx_new_window(cub.screen.mlx_ptr,
				cub.screen.width, cub.screen.height, "Nombre ventana");
		mlx_do_key_autorepeatoff(cub.screen.mlx_ptr);
		mlx_hook(cub.screen.win_ptr, 2, 1L << 0, keypress, &cub);
		mlx_hook(cub.screen.win_ptr, 3, 1L << 1, keyrelease, &cub);
		cub.screen.buffer_img = mlx_new_image(cub.screen.mlx_ptr, \
				cub.screen.width, cub.screen.height);
		cub.screen.addr_img = (unsigned int *)mlx_get_data_addr(\
				cub.screen.buffer_img, &cub.screen.bit, &cub.screen.size_line, \
				&cub.screen.endian);
		load_texture(&cub);
		cub.spr.zbuffer = ft_calloc(cub.screen.width, sizeof(double));
		if (cub.spr.found)
		{
			cub.spr.spriteorder = ft_calloc(cub.spr.found, sizeof(int));
			cub.spr.spritedist = ft_calloc(cub.screen.width, sizeof(double));
		}
		mlx_loop_hook(cub.screen.mlx_ptr, raycaster, &cub);
		mlx_loop(cub.screen.mlx_ptr);
	}
}
