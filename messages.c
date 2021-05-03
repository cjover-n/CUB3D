/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:38:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 19:32:15 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	messages(t_structcub *cub)
{
	int	n;

	n = 0;
	printf("El mapa tiene anchura de: %i\n", cub->screen.width);
	printf("El mapa tiene altura de: %i\n", cub->screen.height);
	printf("Textura norte: %s\n", cub->t_north);
	printf("Textura sur: %s\n", cub->t_south);
	printf("Textura este: %s\n", cub->t_east);
	printf("Textura oeste: %s\n", cub->t_west);
	printf("El sprite es: %s\n", cub->t_sprite);
	printf("Los colores son: %x y %x\n", cub->f_hex, cub->c_hex);
	printf("Caracteres en la primera línea es: %i\n", cub->map_len);
	printf("El mapa tiene este número de líneas: %i\n", cub->map_height);
	while (cub->map[n])
	{
		printf("%s\n", cub->map[n]);
		n++;
	}
	printf("El número de sprites es: %i\n", cub->spr.found);
}
