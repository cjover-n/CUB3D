/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 13:36:05 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler1(int error)
{
	if (error == 1)
	{
		printf("Error\nEl número de parámetros no es correcto.\n");
		exit (1);
	}
	if (error == 2)
	{
		printf("Error\nNo se ha podido leer el archivo del mapa.\n");
		exit (1);
	}
	if (error == 3)
	{
		printf("Error\nError al leer la resolución del mapa.\n");
		exit (1);
	}
	if (error == 4)
	{
		printf("Error\nValor de la resolución es más grande que INT.\n");
		exit (1);
	}
	error_handler2(error);
}

void	error_handler2(int error)
{
	if (error == 5)
	{
		printf("Error\nError con las texturas.\n");
		exit (1);
	}
	if (error == 6)
	{
		printf("Error\nAquí faltan parámetros.\n");
		exit (1);
	}
	if (error == 7)
	{
		printf("Error\nHay caracteres basura en el mapa.\n");
		exit (1);
	}
	if (error == 8)
	{
		printf("Error\nMapa inválido, algún caracter está duplicado.\n");
		exit (1);
	}
	error_handler3(error);
}

void	error_handler3(int error)
{
	if (error == 9)
	{
		printf("Error\nNo se encuentra jugador en el mapa.\n");
		exit (1);
	}
	if (error == 10)
	{
		printf("Error\nHay más de un jugador en el mapa.\n");
		exit (1);
	}
	if (error == 11)
	{
		printf("Error\nMapa incorrecto, no está bien cerrado.\n");
		exit (1);
	}
	if (error == 12)
	{
		printf("Error\nEste archivo no es un .cub !!!! Muy mal.\n");
		exit (1);
	}
	error_handler4(error);
}

void	error_handler4(int error)
{
	if (error == 13)
	{
		printf("Error\nEsto que me pasas no tiene extensión.\n");
		exit (1);
	}
	if (error == 14)
	{
		printf("Error\nEl 3er parámetro debe ser --save para guardar captura.\n");
		exit (1);
	}
	if (error == 15)
	{
		printf("Error\nAquí hay demasiados argumentos y eso no me gusta >_<\n");
		exit (1);
	}
	if (error == 16)
	{
		printf("Error\nEn la resolución has metido cosas de más.\n");
		exit (1);
	}
	error_handler5(error);
}
