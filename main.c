/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:12:52 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/14 16:45:36 by cjover-n         ###   ########lyon.fr   */
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

int     main(int argc, char **argv)
{
    void            *mlx_ptr;
    void            *win_ptr;
    void           *img_ptr;
    t_structcub     cub;

    init_parameters(&cub);
    if (argc != 2)
    {
        ft_printf("AQUÍ FALTAN PARÁMETROS O HAY DEMASIADOS\n");
        return (0);
    }
    else
        readmap(argv[1], &cub);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 700, "Nombre ventana");
    //img_ptr = mlx_new_image(mlx_ptr, 600, 800);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/sky.XPM", &cub.width, &cub.height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    //mlx_get_data_addr(img_ptr, );
    mlx_loop(mlx_ptr);
}