/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:21:19 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/15 17:46:28 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_error(t_structcub *cub, t_errors *error)
{
	error->parameters = 0;
}

void	error_handler1(t_structcub *cub, t_errors *error)
{
	if (error->parameters == 1)
		ft_printf("Error\nEl número de parámetros no es correcto.\n");
	if (error->mapfile == 1)
		ft_printf("Error\nNo se ha podido leer el archivo del mapa.\n");
}