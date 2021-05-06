/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/06 19:59:02 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler1(int error)
{
	if (error == 1)
	{
		printf("Error\nEl número de parámetros no es correcto.\n");
		exit (0);
	}
	if (error == 2)
	{
		printf("Error\nNo se ha podido leer el archivo del mapa.\n");
		exit (0);
	}
	if (error == 3)
	{
		printf("Error\nError al leer la resolución del mapa.\n");
		exit (0);
	}
	if (error == 4)
	{
		printf("Error\nEl mapa tiene caracteres inválidos.\n");
		exit (0);
	}
	error_handler2(error);
}

void	error_handler2(int error)
{
	if (error == 5)
	{
		printf("Error\nError con las texturas.\n");
		exit (0);
	}
	if (error == 6)
	{
		printf("Error\nAquí faltan parámetros.\n");
		exit (0);
	}
	if (error == 7)
	{
		printf("Error\nHay caracteres basura antes/después del mapa.\n");
		exit (0);
	}
	if (error == 8)
	{
		printf("Error\nMapa inválido, algún caracter está duplicado.\n");
		exit (0);
	}
	error_handler3(error);
}

void	error_handler3(int error)
{
	if (error == 9)
	{
		printf("Error\nNo se encuentra jugador en el mapa. ¿Dónde está?\n");
		exit (0);
	}
	if (error == 10)
	{
		printf("Error\nHay más de un jugador en el mapa.\n");
		exit (0);
	}
	if (error == 11)
	{
		printf("Error\nMapa incorrecto, no está bien cerrado.\n");
		exit (0);
	}
	if (error == 12)
	{
		printf("Error\nEste archivo no es un .cub !!!! Muy mal.\n");
		exit (0);
	}
	error_handler4(error);
}

void	error_handler4(int error)
{
	if (error == 13)
	{
		printf("Error\nEsto que me pasas no tiene extensión.\n");
		exit (0);
	}
	if (error == 14)
	{
		printf("Error\nEl 3er parámetro debe ser --save para guardar captura.\n");
		exit (0);
	}
	if (error == 15)
	{
		printf("Error\nAquí hay demasiados argumentos y eso no me gusta >_<\n");
		exit (0);
	}
	if (error == 16)
	{
		printf("Error\nEn la resolución has metido cosas de más.\n");
		exit (0);
	}
	error_handler5(error);
}

void	error_handler5(int error)
{
	if (error == 17)
	{
		printf("Error\nAlguna textura no es válida.\n");
		exit (0);
	}
	if (error == 18)
	{
		printf("Error\nResolución repetida ¬¬\n");
		exit (0);
	}
	if (error == 19)
	{
		printf("Error\nNo tienes textura norte. Perdiste el norte, jeje.\n");
		exit (0);
	}
	if (error == 20)
	{
		printf("Error\nNo tienes textura este.\n");
		exit (0);
	}
	error_handler6(error);
}

void	error_handler6(int error)
{
	if (error == 21)
	{
		printf("Error\nNo tienes textura sur.\n");
		exit (0);
	}
	if (error == 22)
	{
		printf("Error\nNo tienes textura oeste.\n");
		exit (0);
	}
	if (error == 23)
	{
		printf("Error\nEl sprite no es válido.\n");
		exit (0);
	}
	error_handler7(error);
}

void	error_handler7(int error)
{
	if (error == 24)
	{
		printf("Error\nHas metido algo raro en los colores ¬¬\n");
		exit (0);
	}
	if (error == 25)
	{
		printf("Error\nError en el rango de color del mapa.\n");
		exit (0);
	}
	if (error == 26)
	{
		printf("Error\nError en los colores del mapa.\n");
		exit (0);
	}
	if (error == 27)
	{
		printf("Error\nComas mal en el color RGB.\n");
		exit (0);
	}
}
