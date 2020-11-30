/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/30 23:57:58 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, t_structcub *cub)
{
	(void)cub;
	if (key == KEY_ESC)
	{
		//mlx_destroy_image(cub->screen.mlx_ptr, cub->img_ptr);
		mlx_destroy_window(cub->screen.mlx_ptr, cub->screen.win_ptr);
		//free(cub);
		exit(0);
	}
	if (key == KEY_W)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x * 1)] != '1')
			cub->pos_x += cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->dir_y * 1)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->dir_y * cub->movespeed;
	}
	if (key == KEY_A)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->plane_x * 1)] != '1')
			cub->pos_x -= cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->plane_y * 1)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->plane_y * cub->movespeed;
	}
	if (key == KEY_S)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->dir_x * 1)] != '1')
			cub->pos_x -= cub->dir_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->dir_y * 1)][(int)cub->pos_x] != '1')
			cub->pos_y -= cub->dir_y * cub->movespeed;
	}
	if (key == KEY_D)
	{
		if (cub->map[(int)cub->pos_y][(int)(cub->pos_x + cub->plane_x * 1)] != '1')
			cub->pos_x += cub->plane_x * cub->movespeed;
		if (cub->map[(int)(cub->pos_y + cub->plane_y * 1)][(int)cub->pos_x] != '1')
			cub->pos_y += cub->plane_y * cub->movespeed;
	}
	if (key == KEY_UP)
		key = KEY_W;
	if (key == KEY_DOWN)
		key = KEY_S;
	if (key == KEY_LEFT)
		rotation_left(cub);
	if (key == KEY_RIGHT)
		rotation_right(cub);
	return (0);
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
	ft_printf("Numero de caracteres en la primera línea es: %i\n", cub->map_len);
	ft_printf("El mapa tiene este número de líneas: %i\n", cub->map_height);
	while (cub->map[n])
	{
		ft_printf("%s\n", cub->map[n]);
		n++;
	}
}

int     main(int argc, char **argv)
{
    t_structcub		cub;
	t_errors		error;

	ft_bzero(&cub, sizeof(cub));
	ft_bzero(&error, sizeof(error));
    init_parameters(&cub);
    if (argc != 2)
    {
		error.parameters = 1;
		error_handler1(&cub, &error);
        return (0);
    }
    else
	{
		readmap(argv[1], &cub, &error);
		while (cub.map[cub.map_height] != NULL)
		{
			cub.map_height++;
		}
		messages(&cub);
		cub.screen.mlx_ptr = mlx_init();
    	cub.screen.win_ptr = mlx_new_window(cub.screen.mlx_ptr, cub.screen.width, cub.screen.height, "Nombre ventana");
		mlx_key_hook(cub.screen.win_ptr, deal_key, &cub);
		cub.screen.buffer_img = mlx_new_image(cub.screen.mlx_ptr, cub.screen.width, cub.screen.height);
		cub.screen.addr_img = (unsigned int*)mlx_get_data_addr(cub.screen.buffer_img, &cub.bit, &cub.size_line, &cub.endian);
		mlx_loop_hook(cub.screen.mlx_ptr, raycaster, &cub);
		mlx_loop(cub.screen.mlx_ptr);
	}
}