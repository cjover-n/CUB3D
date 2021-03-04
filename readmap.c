/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/04 18:30:10 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    readmap(char *cubmap, t_structcub *cub)
{
    char    *line;
    int     fd;
	int		gnl;
	int		isline;
	char	*map_buffer;

    fd = open(cubmap, O_RDONLY, S_IRUSR);
	isline = 0;
	map_buffer = NULL;
    if (fd >= 3)
    {
        line = NULL;
        while ((gnl = get_next_line(fd, &line)) > 0)
        {
			isline = 0;
			if (!everything_ok(cub))
				line_checker(line, cub);
			else
			{
				if (line[0] != '\0')
				{
					isline = is_map_line(line, cub);
					if (!isline)
					{
						error_handler1(7);
						exit(0);
					}
					else
						get_map(cub, line, &map_buffer);
				}
			}
        }
        gnl_handler(gnl, isline, line, map_buffer, cub);
		close(fd);
    }
}

void	gnl_handler(int gnl, int isline, char *line, char *map_buffer, t_structcub *cub)
{
	if (gnl < 0)
	{
		error_handler1(2);
	}
	else if (!everything_ok(cub))
	{
		error_handler1(6);
	}
	else if (gnl == 0)
	{
		isline = 0;
		isline = is_map_line(line, cub);
		if (!isline)
		{
			error_handler1(7);
			return ;
		}	
		else
			get_map(cub, line, &map_buffer);
		cub->map = ft_split(map_buffer, '.');
		if (flood_check(cub, cub->pos_y, cub->pos_x) == 1)
		{
			error_handler1(11);
			return ;
		}
		free(map_buffer);
	}
}

void    line_checker(char *line, t_structcub *cub)
{
    char    *arr;
    int     len;

    len = ft_strlen(line);
    if ((arr = ft_strchr(line, 'R')))
        resolution_parser(line, cub);
    else if ((arr = ft_strnstr(line, "NO", len)))
        cub->t_north = texture_parser(line);
    else if ((arr = ft_strnstr(line, "EA", len)))
        cub->t_east = texture_parser(line);
    else if ((arr = ft_strnstr(line, "SO", len)))
        cub->t_south = texture_parser(line);
    else if ((arr = ft_strnstr(line, "WE", len)))
        cub->t_west = texture_parser(line);
    else if ((arr = ft_strchr(line, 'S')))
        cub->t_sprite = texture_parser(line);
    else if ((arr = ft_strchr(line, 'F')))
        cub->f_hex = color_parser(line);
    else if ((arr = ft_strchr(line, 'C')))
        cub->c_hex = color_parser(line);
}

int		everything_ok(t_structcub *cub)
{
	int		todo;

	if (!cub->t_north || !cub->t_west || !cub->t_east || !cub->t_south
		|| !cub->t_sprite || !cub->screen.width || !cub->screen.height || !cub->f_hex || !cub->c_hex)
		todo = 0;
	else
		todo = 1;
	return (todo);
}
