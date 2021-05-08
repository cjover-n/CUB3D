/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:25:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/08 21:39:45 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_check1(t_structcub *cub, char *line, int i)
{
	char	*img;

	if (i == 0)
	{
		cub->t_north = texture_parser(cub, line);
		img = ft_strnstr(cub->t_north, ".xpm", ft_strlen(cub->t_north));
		if (!img)
			error_handler1(19);
	}
	if (i == 1)
	{
		cub->t_east = texture_parser(cub, line);
		img = ft_strnstr(cub->t_east, ".xpm", ft_strlen(cub->t_east));
		if (!img)
			error_handler1(20);
	}
	if (i == 2)
	{
		cub->t_south = texture_parser(cub, line);
		img = ft_strnstr(cub->t_south, ".xpm", ft_strlen(cub->t_south));
		if (!img)
			error_handler1(21);
	}
	texture_check2(cub, i, img, line);
}

void	texture_check2(t_structcub *cub, int i, char *img, char *line)
{
	if (i == 3)
	{
		cub->t_west = texture_parser(cub, line);
		img = ft_strnstr(cub->t_west, ".xpm", ft_strlen(cub->t_west));
		if (!img)
			error_handler1(22);
	}
	if (i == 4)
	{
		cub->t_sprite = texture_parser(cub, line);
		img = ft_strnstr(cub->t_sprite, ".xpm", ft_strlen(cub->t_sprite));
		if (!img)
			error_handler1(23);
	}
}

int		something_strange(t_structcub *cub, char *line, int len)
{
	(void)cub;
	if (!(ft_strchr(line, 'R')) && !(ft_strnstr(line, "NO", len)) \
		&& !(ft_strnstr(line, "EA", len)) && !(ft_strnstr(line, "SO", len)) \
		&& !(ft_strnstr(line, "WE", len)) && !(ft_strchr(line, 'S')) \
		&& !(ft_strchr(line, 'F')) && !(ft_strchr(line, 'C')) \
		&& !(ft_strnstr(line, "111", len)) && line[0] != '\0')
		return (1);
	else
		return (0);
}