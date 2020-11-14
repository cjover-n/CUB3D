/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/14 20:30:05 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    readmap(char *cubmap, t_structcub *cub)
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
            linechecker(line, cub);
        }
        if (get_next_line(fd, &line) < 0)
            ft_printf("ARCHIVO MAL, ARCHIVO FATAL\n");
        close(fd);
    }
}

int		ft_numlen(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char    *texture_parser(char *arr)
{
    while (*arr != '.')
        arr++;
    return(ft_strdup(arr));
}

void    linechecker(char *line, t_structcub *cub)
{
    char    *arr;
    int     len;
    int     i;

    len = ft_strlen(line);
    if((arr = ft_strchr(line, 'R')))
    {
        ft_printf("MAPA TIENE RESOLUCION\n");
        i = 0;
        while(!(ft_isdigit(line[i])))
            i++;
        if (ft_isdigit(line[i]))
        {
            cub->width = ft_atoi(&line[i]);
            i = ft_numlen(cub->width) + 3;
            if (ft_isdigit(line[i]) == 1)
                cub->height = ft_atoi(&line[i]);
        }
        else
            ft_printf ("ERROR DE RESOLUCION\n");
        ft_printf("TIENE WIDTH DE %i\n", cub->width);
        ft_printf("TIENE HEIGHT DE %i\n", cub->height);
    }
    else if ((arr = ft_strnstr(line, "NO", len)))
        cub->t_north = texture_parser(line);
    else if ((arr = ft_strnstr(line, "EA", len)))
        cub->t_east = texture_parser(line);
    else if ((arr = ft_strnstr(line, "SO", len)))
        cub->t_south = texture_parser(line);
    else if ((arr = ft_strnstr(line, "WE", len)))
        cub->t_west = texture_parser(line);
    
}