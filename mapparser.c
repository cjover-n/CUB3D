/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:56:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 20:23:00 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution_parser(char *line, t_structcub *cub)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	if (ft_isdigit(line[i]))
	{
		cub->screen.width = ft_atoi(&line[i]);
		i = ft_numlen(cub->screen.width) + 3;
		if (ft_isdigit(line[i]) == 1)
			cub->screen.height = ft_atoi(&line[i]);
	}
	else
		error_handler1(3);
}

char	*texture_parser(char *arr)
{
	while (*arr != '.' && *arr != '\0')
		arr++;
	if (*arr != '.')
	{
		error_handler1(5);
		return (NULL);
	}
	return (arr);
}

unsigned int	color_parser(char *line)
{
	int				i;
	int				x;
	int				color[3];

	i = 1;
	x = 0;
	i = space_checker(line, i);
	while (ft_isdigit(line[i]) && x < 3)
	{
		if (ft_isdigit(line[i]))
		{
			color[x] = ft_atoi(&line[i]);
			if (rgb_range(color[x]) == 0)
				printf("Error\nRango de color mal\n");
			i = i + ft_numlen(color[x]);
		}
		else
			printf("Error\n Color mal\n");
		if (line[i] == ',' || x == 2)
			i++;
		else
			printf("Error\n Comas mal\n");
		x++;
	}
	return (create_trgb(0, color[0], color[1], color[2]));
}
