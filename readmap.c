/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/26 21:42:51 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	readmap(char *cubmap, t_structcub *cub)
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open(cubmap, O_RDONLY, S_IRUSR);
	if (fd >= 3)
	{
		line = NULL;
		while ((gnl = get_next_line(fd, &line)) > 0)
		{
			cub->isline = 0;
			if (!everything_ok(cub))
				line_checker(line, cub);
			else
			{
				if (line[0] != '\0')
				{
					cub->isline = is_map_line(line, cub);
					if (!cub->isline)
						error_handler1(7);
					else
						get_map(cub, line, &cub->map_buff);
				}
			}
		}
		gnl_ch(gnl, line, cub);
		close(fd);
		if (cub->spr.found > 0)
			get_sprites(cub);
	}
}
/*
void	readmap2(char *line, char *cub->map_buff, t_structcub *cub)
{

}
*/

void	gnl_ch(int gnl, char *line, t_structcub *cub)
{
	if (gnl < 0)
		error_handler1(2);
	else if (!everything_ok(cub))
	{
		error_handler1(6);
	}
	else if (gnl == 0)
	{
		cub->isline = 0;
		cub->isline = is_map_line(line, cub);
		if (!cub->isline)
			error_handler1(7);
		else
		{
			get_map(cub, line, &cub->map_buff);
		}
		cub->map = ft_split(cub->map_buff, '.');
		if (flood_check(cub, cub->pos_y, cub->pos_x) == 1)
			error_handler1(11);
		free(cub->map_buff);
	}
}

void	line_checker(char *line, t_structcub *cub)
{
	int		len;

	len = ft_strlen(line);
	if ((ft_strchr(line, 'R')))
		resolution_parser(line, cub);
	else if ((ft_strnstr(line, "NO", len)))
		cub->t_north = texture_parser(line);
	else if ((ft_strnstr(line, "EA", len)))
		cub->t_east = texture_parser(line);
	else if ((ft_strnstr(line, "SO", len)))
		cub->t_south = texture_parser(line);
	else if ((ft_strnstr(line, "WE", len)))
		cub->t_west = texture_parser(line);
	else if ((ft_strchr(line, 'S')))
		cub->t_sprite = texture_parser(line);
	else if ((ft_strchr(line, 'F')))
		cub->f_hex = color_parser(line);
	else if ((ft_strchr(line, 'C')))
		cub->c_hex = color_parser(line);
}

int	everything_ok(t_structcub *cub)
{
	int		todo;

	if (!cub->t_north || !cub->t_west || !cub->t_east || !cub->t_south
		|| !cub->t_sprite || !cub->screen.width || !cub->screen.height
		|| !cub->f_hex || !cub->c_hex)
		todo = 0;
	else
		todo = 1;
	return (todo);
}
