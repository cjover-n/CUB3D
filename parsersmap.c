/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsersmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:56:29 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/15 17:50:23 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    resolution_parser(char *line, t_structcub *cub)
{
    int     i;

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

char    *texture_parser(char *arr)
{
    while (*arr != '.')
        arr++;
    return(ft_strdup(arr));
}

unsigned int    color_parser(char *line, t_structcub *cub)
{
    int             i;
    int             x;
    int             color[3];
    unsigned int    ret;

    i = 1;
    x = 0;
    while (ft_isspace(line[i]))
        i++;
    while (ft_isdigit(line[i]) && x < 3)
    {
        if (ft_isdigit(line[i]))
        {
            color[x] = ft_atoi(&line[i]);
            if (rgb_range(color[x]) == 0)
                ft_printf("Error\nRango de color mal\n");
            i = i + ft_numlen(color[x]);
        }     
        else
            ft_printf("Error\n Color mal\n");
        if (line[i] == ',' || x == 2)
            i++;
        else
            ft_printf("Error\n Comas mal\n");
        x++;
    }
    ret = create_trgb(0, color[0], color[1], color[2]);
    return (ret);
}

