/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:46 by cjover-n          #+#    #+#             */
/*   Updated: 2020/11/29 15:15:22 by cjover-n         ###   ########.fr       */
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

#define RED 0x00FF0000
#define BLUE 0x000000FF
#define GREEN 0x0000FF00
#define YELLOW 0x00FFFF00

typedef struct s_screen
{
	void			*mlx_ptr;
    void			*win_ptr;
	void			*buffer_img;
	int				width;
    int				height;
	unsigned int	*addr_img;
}				t_structscreen;

typedef struct s_structcub 
{
	t_structscreen	screen;
	int				x;
    void			*img_ptr;
	int				bit;
	int				endian;
	int				size_line;//va a ser igual que cub.screen.width * 4
	double			camerax;
	double			deltadist_x;
	double			deltadist_y;
	//int				stpx;
	//int				stpy;
	double			sidedist_x;
	double			sidedist_y;
    double			rotspeed;
    double			movespeed;
    double			pos_x;//posicion del jugador, el mismo cambio en pos se aplica a plane
    double			pos_y;
    double			dir_x;//plano x del mapa
    double			dir_y;//el plano "y" empieza en -1 OJO!!
    double			plane_x;//direccion de la camara, linea perpendicular al jugador
    double			plane_y;
	double			raydirx;
	double			raydiry;
	double			perpwalldist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				draw_start;
	int				draw_end;
    char			*t_east;
    char			*t_south;
    char			*t_north;
    char			*t_west;
    char			*t_sprite;
    char			**map;
    unsigned int	f_hex;
    unsigned int    c_hex;
	unsigned int	color;
	int				isline;
	int				map_len;
	int				map_height;
	int				start_copy;
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
	int				duplicate;
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
int				raycaster(t_structcub *cub);
void			step(t_structcub *cub);

#endif
