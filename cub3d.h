/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:43:46 by cjover-n          #+#    #+#             */
/*   Updated: 2021/01/31 20:39:52 by cjover-n         ###   ########lyon.fr   */
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

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_T 17

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

typedef struct s_texture
{
	void			*t_north;
	void			*t_east;
	void			*t_south;
	void			*t_west;
	unsigned int	*addr_north;
	unsigned int	*addr_south;
	unsigned int	*addr_east;
	unsigned int	*addr_west;
	int				t_n_height;
	int				t_n_width;
	int				t_s_height;
	int				t_s_width;
	int				t_e_height;
	int				t_e_width;
	int				t_w_height;
	int				t_w_width;
	unsigned int	*active;
	int				active_width;
	int				active_height;
	double			wallx;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}				t_structtexture;

typedef struct s_player
{
	int				player_ok;
	int				player_north;
	int				player_east;
	int				player_south;
	int				player_west;
}				t_structplayer;

typedef struct s_structcub
{
	t_structscreen	screen;
	t_structplayer	player;
	t_structtexture	texture;
	int				x;
    //void			*img_ptr;
	int				bit;
	int				endian;
	int				size_line;//va a ser igual que cub.screen.width * 4
	double			camerax;
	double			deltadist_x;
	double			deltadist_y;
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
	int				end_copy;
	int				line_counter;
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
	int				noplayer;
	int				toomanyplayers;
}				t_errors;

void			init_parameters(t_structcub *cub);
void			error_handler1(t_structcub *cub, t_errors *error);
void			messages(t_structcub *cub);
int				deal_key(int key, t_structcub *cub);
void			vertical_movement(t_structcub *cub);
void			horizontal_movement(t_structcub *cub);
void			rotation_right(t_structcub *cub);
void			rotation_left(t_structcub *cub);
void			readmap(char *cubmap, t_structcub *cub, t_errors *error);
void			gnl_handler(int gnl, int isline, char *line, char *map_buffer, t_structcub *cub, t_errors *error);
void			line_checker(char *line, t_structcub *cub, t_errors *error);
void			resolution_parser(char *line, t_structcub *cub, t_errors *error);
int				rgb_range(int cr);
unsigned int	create_trgb(int t, int r, int g, int b);
char			*texture_parser(char *arr, t_structcub *cub, t_errors *error);
unsigned int	color_parser(char *line);
int				space_checker(char *line, int i);
int				is_map_line(char *line, t_structcub *cub, t_errors *error);
int				everything_ok(t_structcub *cub);
void			get_map(t_structcub *cub, char *line, char **buffer);
int				raycaster(t_structcub *cub);
void			step(t_structcub *cub);
void			get_player(t_structcub *cub, char line, int i, t_errors *error);
void			player_north(t_structcub *cub);
void			player_east(t_structcub *cub);
void			player_south(t_structcub *cub);
void			player_west(t_structcub *cub);
void			destroy_and_exit(t_structcub *cub);
void			textures(t_structcub *cub);
void			plain_color(t_structcub *cub);
void			load_texture(t_structcub *cub);
void			texture_calculation(t_structcub *cub);
void			texture_color_selector(t_structcub *cub);
void			texture_floor_ceiling(t_structcub *cub);
void			floodfill(t_structcub *cub, int posy, int posx);

#endif
