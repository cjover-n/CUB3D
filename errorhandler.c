/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/27 12:33:34 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler1(t_structcub *cub, t_errors *error)
{
	(void)cub;
	if (error->parameters == 1)
		ft_printf("Error\nEl número de parámetros no es correcto.\n");
	if (error->mapfile == 1)
		ft_printf("Error\nNo se ha podido leer el archivo del mapa.\n");
	if (error->resolution == 1)
		ft_printf("Error\nError al leer la resolución del mapa.\n");
	if (error->badchars == 1)
		ft_printf("Error\nEl mapa tiene caracteres inválidos.\n");
	if (error->badtexture == 1)
		ft_printf("Error\nError con las texturas.\n");
	if (error->everythingnotok == 1)
		ft_printf("Error\nAquí faltan parámetros.\n");
	if (error->maptrash == 1)
		ft_printf("Error\nHay caracteres basura antes/después del mapa.\n");
	if (error->duplicate == 1)
		ft_printf("Error\nMapa inválido, algún caracter está duplicado.\n");
	if (error->noplayer == 1)
		ft_printf("Error\nNo se encuentra jugador en el mapa. ¿Dónde está?\n");
	if (error->toomanyplayers == 1)
		ft_printf("Error\nHay más de un jugador en el mapa.\n");
}
