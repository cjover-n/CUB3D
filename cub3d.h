/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:46 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/09 22:11:06 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "./Libft/libft.h"

typedef struct s_structcub 
{
    int     width;
    int     height;
    double  rotspeed;
    double  movespeed;
    double  posx;//posicion del jugador, el mismo cambio en pos se aplica a plane
    double  posy;
    double  dirx;//plano x del mapa
    double  diry;//el plano "y" empieza en -1 OJO!!
    double  planex;//direccion de la camara, linea perpendicular al jugador
    double  planey;
    char    *t_east;
    char    *t_south;
    char    *t_north;
    char    *t_west;
    char    **map;
}              t_structcub;

void    ft_init_parameters(t_structcub *cub);
void    readmap(char *cubmap, t_structcub *cub);
void    linechecker(char *line, t_structcub *cub);
int     ft_numlen(int n);

#endif
