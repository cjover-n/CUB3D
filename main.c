/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/04 21:01:49 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_and_exit(t_structcub *cub)
{
	mlx_destroy_image(cub->screen.mlx_ptr, cub->screen.buffer_img);
	mlx_destroy_window(cub->screen.mlx_ptr, cub->screen.win_ptr);
	free(cub->spr.zbuffer);
	if (cub->spr.found)
		free(cub->spr.spriteorder);
	if (cub->spritelist)
		free(cub->spritelist);
	exit(0);
}

void	messages(t_structcub *cub)
{
	int n;

	n = 0;
	ft_printf("El mapa tiene anchura de: %i\n", cub->screen.width);
	ft_printf("El mapa tiene altura de: %i\n", cub->screen.height);
	ft_printf("Textura norte: %s\n", cub->t_north);
	ft_printf("Textura sur: %s\n", cub->t_south);
	ft_printf("Textura este: %s\n", cub->t_east);
	ft_printf("Textura oeste: %s\n", cub->t_west);
	ft_printf("El sprite es: %s\n", cub->t_sprite);
	ft_printf("Los colores son: %x y %x\n", cub->f_hex, cub->c_hex);
	ft_printf("Caracteres en la primera línea es: %i\n", cub->map_len);
	ft_printf("El mapa tiene este número de líneas: %i\n", cub->map_height);
	while (cub->map[n])
	{
		ft_printf("%s\n", cub->map[n]);
		n++;
	}
	ft_printf("El número de sprites es: %i\n", cub->spr.found);
}

int		main(int argc, char **argv)
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
		mlx_key_hook(cub.screen.win_ptr, deal_key, &cub);
		cub.screen.buffer_img = mlx_new_image(cub.screen.mlx_ptr,
			cub.screen.width, cub.screen.height);
		cub.screen.addr_img = (unsigned int*)mlx_get_data_addr(
			cub.screen.buffer_img, &cub.bit, &cub.size_line, &cub.endian);
		load_texture(&cub);
		cub.spr.zbuffer = ft_calloc(cub.screen.width, sizeof(double));
		if (!(cub.spritelist = malloc(sizeof(t_spritelist) * cub.spr.found)))
			return (0);
		if (cub.spr.found)
		{
			cub.spr.spriteorder = ft_calloc(cub.spr.found, sizeof(int));
			cub.spr.spritedistance = ft_calloc(cub.screen.width, sizeof(double));
		}
		mlx_loop_hook(cub.screen.mlx_ptr, raycaster, &cub);
		mlx_loop(cub.screen.mlx_ptr);
	}
}
