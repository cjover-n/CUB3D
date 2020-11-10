/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/10 21:38:31 by cjover-n         ###   ########.fr       */
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
    /*
    char    **arr;
    int     i;

    arr= ft_split(line, ' ');
    i = 0;
    if (arr[0][0] == 'R')
    {
        ft_printf("MAPA TIENE RESOLUCION\n");
        i = 2;
        if (ft_isdigit(line[i]) == 1)
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
    if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
    {
        ft_printf("EL MAPA TIENE TEXTURA ESTE\n");
        i = 3;
        
    }

    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        ft_printf("EL MAPA TIENE TEXTURA NORTE\n");
    if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        ft_printf("EL MAPA TIENE TEXTURA SUR\n");
    if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        ft_printf("EL MAPA TIENE TEXTURA OESTE\n");
*/
}