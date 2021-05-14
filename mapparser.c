/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:56:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:21:41 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	height_width_check(t_structcub *cub, int id)
{
	if (id == 0)
	{
		cub->w_len = ft_numlen(cub->screen.width);
		if (cub->screen.width > 2560)
			cub->screen.width = 2560;
		if (cub->screen.width == -1)
			error_handler1(4);
	}
	if (id == 1)
	{
		cub->h_len = ft_numlen(cub->screen.height);
		if (cub->screen.height > 1395)
			cub->screen.height = 1395;
		if (cub->screen.height == -1)
			error_handler1(4);
	}
}

char	*texture_parser(t_structcub *cub, char *arr)
{
	(void)cub;
	while (*arr != '.' && *arr != '\0')
		arr++;
	if (*arr != '.')
		error_handler1(5);
	return (arr);
}

void	color_asign(t_structcub *cub, char *line, int id)
{
	if (id == 0)
	{
		cub->f_hex = color_parser1(cub, line);
		cub->ff = 1;
	}
	if (id == 1)
	{
		cub->c_hex = color_parser1(cub, line);
		cub->cf = 1;
	}
}

unsigned int	color_parser1(t_structcub *cub, char *line)
{
	cub->col_x = 0;
	cub->col_i = space_checker(line, 1);
	if (ft_isspace(line[cub->col_i]))
		cub->col_i++;
	while (ft_isdigit(line[cub->col_i]))
	{
		if (ft_isdigit(line[cub->col_i]))
			color_parser2(cub, line);
		else
			error_handler1(26);
		if (line[cub->col_i] == ',')
			cub->col_x++;
		cub->col_i += (line[cub->col_i] != '\0');
	}
	if (cub->col_x != 2)
		error_handler1(27);
	return (create_trgb(0, cub->c_color[0], cub->c_color[1], cub->c_color[2]));
}

void	color_parser2(t_structcub *cub, char *line)
{
	cub->c_color[cub->col_x] = ft_atoi_cub(line + cub->col_i);
	if (!ft_isdigit(line[cub->col_i + 1]) && line[cub->col_i + 1] != ',' \
		&& line[cub->col_i + 1] != '\0')
		error_handler1(24);
	if (rgb_range(cub->c_color[cub->col_x]) == 0)
		error_handler1(25);
	while (ft_isdigit(line[cub->col_i]))
		cub->col_i++;
}
