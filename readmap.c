/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/15 17:47:09 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    readmap(char *cubmap, t_structcub *cub, t_errors *error)
{
    char    *line;
    int     fd;
    int     *res;

    fd = open(cubmap, O_RDONLY, S_IRUSR);
    res = NULL;
    if (fd >= 3)
    {
        line = NULL;
        while (get_next_line(fd, &line) > 0)
        {
            line_checker(line, cub);
        }
        if (get_next_line(fd, &line) < 0)
		{
			error->mapfile = 1;
			error_handler1(cub, error);
		}
        close(fd);
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
        cub->f_hex = color_parser(line, cub);
    else if ((arr = ft_strchr(line, 'C')))
        cub->c_hex = color_parser(line, cub);
}
