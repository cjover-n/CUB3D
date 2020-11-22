/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:46 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/22 14:36:44 by cjover-n         ###   ########.fr       */
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
    double			pos_x;//posicion del jugador, el mismo cambio en pos se aplica a plane
    double			pos_y;
    double			dir_x;//plano x del mapa
    double			dir_y;//el plano "y" empieza en -1 OJO!!
    double			plane_x;//direccion de la camara, linea perpendicular al jugador
    double			plane_y;
    char			*t_east;
    char			*t_south;
    char			*t_north;
    char			*t_west;
    char			*t_sprite;
    char			**map;
    unsigned int	f_hex;
    unsigned int    c_hex;
	int				isline;
	int				map_len;
}				t_structcub;

typedef struct s_errors
{
    int				parameters;
    int				mapfile;
	int				resolution;
	int				badchars;
	int				badtexture;
	int				everythingnotok;
	int				maptrash;
}				t_errors;

void			init_parameters(t_structcub *cub);
void			error_handler1(t_structcub *cub, t_errors *error);
void			messages(t_structcub *cub);
void			readmap(char *cubmap, t_structcub *cub, t_errors *error);
void			line_checker(char *line, t_structcub *cub, t_errors *error);
void			resolution_parser(char *line, t_structcub *cub, t_errors *error);
int				rgb_range(int cr);
unsigned int	create_trgb(int t, int r, int g, int b);
char			*texture_parser(char *arr, t_structcub *cub, t_errors *error);
unsigned int	color_parser(char *line, t_structcub *cub);
void			space_checker(char *line, int i);
int				is_map_line(char *line, t_structcub *cub, t_errors *error);
int				everything_ok(t_structcub *cub);
void			get_map(char *line, char **buffer);


#endif
