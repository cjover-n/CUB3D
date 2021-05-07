/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/07 21:14:18 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parameters(t_structcub *cub)
{
	cub->rotspeed = 0.01;
	cub->movespeed = 0.09;
	cub->buf = 4;
}

void	keyhandle(t_structcub *cub)
{
	mlx_do_key_autorepeatoff(cub->screen.mlx_ptr);
	mlx_hook(cub->screen.win_ptr, 2, 1L << 0, keypress, cub);
	mlx_hook(cub->screen.win_ptr, 3, 1L << 1, keyrelease, cub);
	mlx_hook(cub->screen.win_ptr, 17, 0, destroy_and_exit, cub);
}

void	file_checker(char **argv)
{
	char	*tmp;

	if ((ft_strchr(argv[1], '.')))
	{
		tmp = ft_strchr(argv[1], '.');
		if (!(*++tmp == 'c' && *++tmp == 'u' && *++tmp == 'b' && *++tmp == '\0'))
			error_handler1(12);
	}
	else
		error_handler1(13);
}

void	cub_core(t_structcub *cub, char **argv)
{
	readmap(argv[1], cub);
	if (cub->player.player_ok == 0)
		error_handler1(9);
	while (cub->map[cub->map_height] != NULL)
		cub->map_height++;
	cub->screen.mlx_ptr = mlx_init();
	cub->screen.win_ptr = mlx_new_window(cub->screen.mlx_ptr, \
			cub->screen.width, cub->screen.height, "Cub3D");
	keyhandle(cub);
	cub->screen.buffer_img = mlx_new_image(cub->screen.mlx_ptr, \
			cub->screen.width, cub->screen.height);
	cub->screen.addr_img = (unsigned int *)mlx_get_data_addr(\
			cub->screen.buffer_img, &cub->screen.bit, &cub->screen.size_line, \
			&cub->screen.endian);
	load_texture1(cub);
	cub->spr.zbuffer = ft_calloc(cub->screen.width, sizeof(double));
	messages(cub);
	if (cub->spr.found)
	{
		cub->spr.spriteorder = ft_calloc(cub->spr.found, sizeof(int));
		cub->spr.spritedist = ft_calloc(cub->screen.width, sizeof(double));
	}
	mlx_loop_hook(cub->screen.mlx_ptr, raycaster, cub);
	mlx_loop(cub->screen.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_structcub	cub;

	file_checker(argv);
	ft_bzero(&cub, sizeof(cub));
	init_parameters(&cub);
	if (argc < 2)
		error_handler1(1);
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", -1))
			error_handler1(14);
		else
			cub.bmp = 1;
		cub_core(&cub, argv);
	}
	else if (argc == 2)
		cub_core(&cub, argv);
	else if (argc > 3)
		error_handler1(15);
	return (0);
}
