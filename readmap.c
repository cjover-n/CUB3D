/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/07 07:52:19 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	readmap(char *cubmap, t_structcub *cub)
{
	char	*line;
	int		fd;

	fd = open(cubmap, O_RDONLY, S_IRUSR);
	if (fd >= 3)
	{
		line = NULL;
		gnl(line, fd, cub);
		close(fd);
		if (cub->spr.found > 0)
			get_sprites(cub);
		free(line);
	}
}

void	gnl(char *line, int fd, t_structcub *cub)
{
	int	gnl;

	gnl = get_next_line(fd, &line);
	while (gnl > 0)
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
				{
					free(line);
					error_handler_free(line, 1);
					//error_handler1(7);
				}
				else
					get_map(cub, line, &cub->map_buff);
			}
		}
		free(line);
		gnl = get_next_line(fd, &line);
	}
	gnl_ch(gnl, line, cub);
	free(line);
}

void	gnl_ch(int gnl, char *line, t_structcub *cub)
{
	if (gnl < 0)
		error_handler1(2);
	else if (gnl == 0)
	{
		cub->isline = 0;
		cub->isline = is_map_line(line, cub);
		if (!cub->isline && *line != '\0')
			error_handler1(7);
		else
			get_map(cub, line, &cub->map_buff);
		cub->map = ft_split(cub->map_buff, '.');
		if (flood_check(cub, cub->pos_y, cub->pos_x) == 1)
			error_handler1(11);
		free(cub->map_buff);
	}
	else if (!everything_ok(cub))
		error_handler1(6);

}

void	line_checker(char *line, t_structcub *cub)
{
	int		len;

	len = ft_strlen(line);
	if ((ft_strchr(line, 'R')))
		resolution_parser(line, cub);
	else if ((ft_strnstr(line, "NO", len)))
		texture_check1(cub, line, 0);
	else if ((ft_strnstr(line, "EA", len)))
		texture_check1(cub, line, 1);
	else if ((ft_strnstr(line, "SO", len)))
		texture_check1(cub, line, 2);
	else if ((ft_strnstr(line, "WE", len)))
		texture_check1(cub, line, 3);
	else if ((ft_strchr(line, 'S')))
		texture_check1(cub, line, 4);
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
