/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:29:09 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parameters(t_structcub *cub)
{
	cub->rotspeed = 0.01;
	cub->movespeed = 0.09;
	cub->buf = 4;
}

void	readmap(char *cubmap, t_structcub *cub)
{
	char	*line;
	int		fd;

	fd = open(cubmap, O_RDONLY, S_IRUSR);
	if (fd >= 3)
	{
		line = NULL;
		gnl(line, fd, cub);
		close(fd);
		if (cub->spr.found > 0)
			get_sprites(cub);
		free(line);
	}
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
		cub->spr.spriteorder = ft_calloc(cub->spr.found, sizeof(int));
	run_raycaster(cub);
}

void	run_raycaster(t_structcub *cub)
{
	if (cub->bmp)
	{
		raycaster(cub);
		screenshot(cub);
	}
	else
	{
		mlx_loop_hook(cub->screen.mlx_ptr, raycaster, cub);
		mlx_loop(cub->screen.mlx_ptr);
	}
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
