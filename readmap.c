/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/01/03 11:18:35 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    readmap(char *cubmap, t_structcub *cub, t_errors *error)
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
            	line_checker(line, cub, error);
			else
			{
				if (line[0] != '\0')
				{
					isline = is_map_line(line, cub, error);
					if (!isline)
					{
						error->maptrash = 1;
						error_handler1(cub, error);
						return ;
					}
					else
					{
						get_map(line, &map_buffer);
					}
				}
			}
        }
        gnl_handler(gnl, isline, line, map_buffer, cub, error);
		close(fd);
    }
}

void	gnl_handler(int gnl, int isline, char *line, char *map_buffer, t_structcub *cub, t_errors *error)
{
	if (gnl < 0)
		{
			error->mapfile = 1;
			error_handler1(cub, error);
		}
		else if (!everything_ok(cub))
		{
			error->everythingnotok = 1;
			error_handler1(cub, error);
		}
		else if (gnl == 0)
		{
			isline = 0;
			isline = is_map_line(line, cub, error);
			if (!isline)
			{
				error->maptrash = 1;
				error_handler1(cub, error);
				return ;
			}
			else
			{
				get_map(line, &map_buffer);
			}
			cub->map = ft_split(map_buffer, '.');
			free(map_buffer);
		}
}

void    line_checker(char *line, t_structcub *cub, t_errors *error)
{
    char    *arr;
    int     len;

    len = ft_strlen(line);
    if ((arr = ft_strchr(line, 'R')))
        resolution_parser(line, cub, error);
    else if ((arr = ft_strnstr(line, "NO", len)))
        cub->t_north = texture_parser(line, cub, error);
    else if ((arr = ft_strnstr(line, "EA", len)))
        cub->t_east = texture_parser(line, cub, error);
    else if ((arr = ft_strnstr(line, "SO", len)))
        cub->t_south = texture_parser(line, cub, error);
    else if ((arr = ft_strnstr(line, "WE", len)))
        cub->t_west = texture_parser(line, cub, error);
    else if ((arr = ft_strchr(line, 'S')))
        cub->t_sprite = texture_parser(line, cub, error);
    else if ((arr = ft_strchr(line, 'F')))
        cub->f_hex = color_parser(line, cub);
    else if ((arr = ft_strchr(line, 'C')))
        cub->c_hex = color_parser(line, cub);
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
