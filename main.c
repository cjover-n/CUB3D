/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/22 13:57:57 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int     deal_key(int key, void *param)
{
    
    //mlx_pixel_put(mlx_ptr, win_ptr);
    if (key == 0x35 || key == 0x00)
	{
		ft_printf("\n**** THANKS FOR PLAYING! :D ****\n\n");
		//exit();
	}
    return (0);
}
*/

void	messages(t_structcub *cub)
{
	int n;
	
	n = 0;
	ft_printf("El mapa tiene anchura de: %i\n", cub->width);
	ft_printf("El mapa tiene altura de: %i\n", cub->height);
    ft_printf("Textura norte: %s\n", cub->t_north);
	ft_printf("Textura sur: %s\n", cub->t_south);
	ft_printf("Textura este: %s\n", cub->t_east);
	ft_printf("Textura oeste: %s\n", cub->t_west);
	ft_printf("El sprite es: %s\n", cub->t_sprite);
	ft_printf("Los colores son: %x y %x\n", cub->f_hex, cub->c_hex);
	ft_printf("Numero de caracteres en la primera línea es: %i\n", cub->map_len);
	while (cub->map[n])
	{
		ft_printf("%s\n", cub->map[n]);
		n++;
	}
}

int     main(int argc, char **argv)
{
    //void			*mlx_ptr;
    //void			*win_ptr;
    //void			*img_ptr;
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
        readmap(argv[1], &cub, &error);
	/*
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 700, "Nombre ventana");
    //img_ptr = mlx_new_image(mlx_ptr, 600, 800);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/pink.xpm", &cub.width, &cub.height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    //mlx_get_data_addr(img_ptr, );
    mlx_loop(mlx_ptr);
	*/
}