/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:38:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/28 14:39:09 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	messages(t_structcub *cub)
{
	int	n;

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
