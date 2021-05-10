/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:33:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/10 21:29:13 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler5(int error)
{
	if (error == 17)
	{
		printf("Error\nAlguna textura no es válida.\n");
		exit (1);
	}
	if (error == 18)
	{
		printf("Error\nResolución repetida ¬¬\n");
		exit (1);
	}
	if (error == 19)
	{
		printf("Error\nNo tienes textura norte.\n");
		exit (1);
	}
	if (error == 20)
	{
		printf("Error\nNo tienes textura este.\n");
		exit (1);
	}
	error_handler6(error);
}

void	error_handler6(int error)
{
	if (error == 21)
	{
		printf("Error\nNo tienes textura sur.\n");
		exit (1);
	}
	if (error == 22)
	{
		printf("Error\nNo tienes textura oeste.\n");
		exit (1);
	}
	if (error == 23)
	{
		printf("Error\nEl sprite no es válido.\n");
		exit (1);
	}
	error_handler7(error);
}

void	error_handler7(int error)
{
	if (error == 24)
	{
		printf("Error\nColor falta o es inválido\n");
		exit (1);
	}
	if (error == 25)
	{
		printf("Error\nError en el rango de color del mapa.\n");
		exit (1);
	}
	if (error == 26)
	{
		printf("Error\nError en los colores del mapa.\n");
		exit (1);
	}
	if (error == 27)
	{
		printf("Error\nComas mal en el color RGB.\n");
		exit (1);
	}
	if (error == 28)
	{
		printf("Error\nTextura o color inválido dentro del .cub.\n");
		exit (1);
	}
}
