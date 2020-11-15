/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:46 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/15 17:46:52 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "./Libft/libft.h"

typedef struct s_structcub 
{
    int				width;
    int				height;
    double			rotspeed;
    double			movespeed;
    double			posX;//posicion del jugador, el mismo cambio en pos se aplica a plane
    double			posY;
    double			dirX;//plano x del mapa
    double			dirY;//el plano "y" empieza en -1 OJO!!
    double			planeX;//direccion de la camara, linea perpendicular al jugador
    double			planeY;
    char			*t_east;
    char			*t_south;
    char			*t_north;
    char			*t_west;
    char			*t_sprite;
    char			**map;
    unsigned int	f_hex;
    unsigned int    c_hex;
}				t_structcub;

typedef struct s_errors
{
    int				parameters;
    int				mapfile;
}				t_errors;

void			init_parameters(t_structcub *cub);
void			init_error(t_structcub *cub, t_errors *error);
void			error_handler1(t_structcub *cub, t_errors *error);
void			readmap(char *cubmap, t_structcub *cub, t_errors *error);
void			line_checker(char *line, t_structcub *cub);
void			resolution_parser(char *line, t_structcub *cub);
int				rgb_range(int cr);
unsigned int	create_trgb(int t, int r, int g, int b);
char			*texture_parser(char *arr);
unsigned int	color_parser(char *line, t_structcub *cub);


#endif
