/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 20:26:07 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler1(int error)
{
	if (error == 1)
	{
		printf("Error\nEl número de parámetros no es correcto.\n");
		return ;
	}
	if (error == 2)
	{
		printf("Error\nNo se ha podido leer el archivo del mapa.\n");
		return ;
	}
	if (error == 3)
	{
		printf("Error\nError al leer la resolución del mapa.\n");
		return ;
	}
	if (error == 4)
	{
		printf("Error\nEl mapa tiene caracteres inválidos.\n");
		return ;
	}
	error_handler2(error);
}

void	error_handler2(int error)
{
	if (error == 5)
	{
		printf("Error\nError con las texturas.\n");
		return ;
	}
	if (error == 6)
	{
		printf("Error\nAquí faltan parámetros.\n");
		return ;
	}
	if (error == 7)
	{
		printf("Error\nHay caracteres basura antes/después del mapa.\n");
		return ;
	}
	if (error == 8)
	{
		printf("Error\nMapa inválido, algún caracter está duplicado.\n");
		return ;
	}
	error_handler3(error);
}

void	error_handler3(int error)
{
	if (error == 9)
	{
		printf("Error\nNo se encuentra jugador en el mapa. ¿Dónde está?\n");
		return ;
	}
	if (error == 10)
	{
		printf("Error\nHay más de un jugador en el mapa.\n");
		return ;
	}
	if (error == 11)
	{
		printf("Error\nMapa mal.\n");
		return ;
	}
}
