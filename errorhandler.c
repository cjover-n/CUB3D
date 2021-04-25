/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/19 23:47:59 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler1(int error)
{
	if (error == 1)
	{
		ft_printf("Error\nEl número de parámetros no es correcto.\n");
		return ;
	}
	if (error == 2)
	{
		ft_printf("Error\nNo se ha podido leer el archivo del mapa.\n");
		return ;
	}
	if (error == 3)
	{
		ft_printf("Error\nError al leer la resolución del mapa.\n");
		return ;
	}
	if (error == 4)
	{
		ft_printf("Error\nEl mapa tiene caracteres inválidos.\n");
		return ;
	}
	if (error == 5)
	{
		ft_printf("Error\nError con las texturas.\n");
		return ;
	}
	if (error == 6)
	{
		ft_printf("Error\nAquí faltan parámetros.\n");
		return ;
	}
	if (error == 7)
	{
		ft_printf("Error\nHay caracteres basura antes/después del mapa.\n");
		return ;
	}
	if (error == 8)
	{
		ft_printf("Error\nMapa inválido, algún caracter está duplicado.\n");
		return ;
	}
	if (error == 9)
	{
		ft_printf("Error\nNo se encuentra jugador en el mapa. ¿Dónde está?\n");
		return ;
	}
	if (error == 10)
	{
		ft_printf("Error\nHay más de un jugador en el mapa.\n");
		return ;
	}
	if (error == 11)
	{
		ft_printf("Error\nMapa mal.\n");
		return ;
	}
}
