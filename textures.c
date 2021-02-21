/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:52:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/21 18:57:14 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_structcub *cub)
{
	cub->texture.t_north = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_north, &cub->texture.t_n_width, &cub->texture.t_n_height);
	cub->texture.addr_north = (unsigned int *)mlx_get_data_addr(cub->texture.t_north,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->texture.t_east = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_east, &cub->texture.t_e_width, &cub->texture.t_e_height);
	cub->texture.addr_east = (unsigned int *)mlx_get_data_addr(cub->texture.t_east,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->texture.t_south = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_south, &cub->texture.t_s_width, &cub->texture.t_s_height);
	cub->texture.addr_south = (unsigned int *)mlx_get_data_addr(cub->texture.t_south,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->texture.t_west = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_west, &cub->texture.t_w_width, &cub->texture.t_w_height);
	cub->texture.addr_west = (unsigned int *)mlx_get_data_addr(cub->texture.t_west,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->sprite.t_sprite = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_sprite, &cub->sprite.s_width, &cub->sprite.s_height);
	cub->sprite.addr_sprite = (unsigned int *)mlx_get_data_addr(cub->sprite.t_sprite,
		&cub->bit, &cub->size_line, &cub->endian);
}

void	plain_color(t_structcub *cub)
{
	if (cub->side == 0 && cub->raydirx > 0)
		cub->color = RED;
	else if (cub->side == 0 && cub->raydirx < 0)
		cub->color = BLUE;
	else if (cub->side == 1 && cub->raydiry > 0)
		cub->color = GREEN;
	else if (cub->side == 1 && cub->raydiry < 0)
		cub->color = YELLOW;
	cub->start_copy = cub->draw_start;
	cub->end_copy = cub->draw_end;
	while (cub->start_copy < cub->draw_end)
		cub->screen.addr_img[cub->start_copy++ * cub->screen.width + cub->x] = cub->color;//importante: y * w + x
}

void	textures(t_structcub *cub)
{
	if (cub->side == 0)
		cub->texture.wallx = cub->pos_y + cub->perpwalldist * cub->raydiry;
	else
		cub->texture.wallx = cub->pos_x + cub->perpwalldist * cub->raydirx;
	cub->texture.wallx -= floor(cub->texture.wallx);
	cub->texture.tex_x = (int)(cub->texture.wallx * (double)cub->texture.active_width);
	if (cub->side == 0 && cub->raydirx > 0)
		cub->texture.tex_x = cub->texture.active_width - cub->texture.tex_x - 1;
	if (cub->side == 1 && cub->raydiry < 0)
		cub->texture.tex_x = cub->texture.active_width - cub->texture.tex_x - 1;
	cub->start_copy = cub->draw_start;
	cub->end_copy = cub->draw_end;
	texture_calculation(cub);
	texture_color_selector(cub);
	texture_floor_ceiling(cub);
}

void	texture_calculation(t_structcub *cub)
{
	if (cub->side == 0 && cub->raydirx > 0)
	{
		cub->texture.active = cub->texture.addr_east;
		cub->texture.active_width = cub->texture.t_e_width;
		cub->texture.active_height = cub->texture.t_e_height;
	}
	else if (cub->side == 0 && cub->raydirx < 0)
	{
		cub->texture.active = cub->texture.addr_west;
		cub->texture.active_width = cub->texture.t_w_width;
		cub->texture.active_height = cub->texture.t_w_height;
	}
	else if (cub->side == 1 && cub->raydiry > 0)
	{
		cub->texture.active = cub->texture.addr_south;
		cub->texture.active_width = cub->texture.t_s_width;
		cub->texture.active_height = cub->texture.t_s_height;
	}
	else if (cub->side == 1 && cub->raydiry < 0)
	{
		cub->texture.active = cub->texture.addr_north;
		cub->texture.active_width = cub->texture.t_n_width;
		cub->texture.active_height = cub->texture.t_n_height;
	}

	//plain_color(cub);
}

void	texture_color_selector(t_structcub *cub)
{
	int		y;

	y = cub->draw_start;
	cub->texture.step = 1.0 * cub->texture.active_height / cub->lineheight;
	cub->texture.tex_pos = (cub->draw_start - cub->screen.height / 2 + cub->lineheight / 2) * cub->texture.step;
	while (y < cub->draw_end)
	{
		cub->texture.tex_y = (int)cub->texture.tex_pos & (cub->texture.active_height - 1);
		cub->texture.tex_pos += cub->texture.step;
		cub->color = cub->texture.active[cub->texture.active_width * cub->texture.tex_y + cub->texture.tex_x];
		cub->screen.addr_img[y * cub->screen.width + cub->x] = cub->color;
		y++;
	}
}

void	texture_floor_ceiling(t_structcub *cub)
{
	while (cub->side < cub->start_copy)
		cub->screen.addr_img[cub->side++ * cub->screen.width + cub->x] = cub->c_hex;
	cub->side = cub->draw_end;
	while (cub->side < cub->screen.height)
		cub->screen.addr_img[cub->side++ * cub->screen.width + cub->x] = cub->f_hex;
}
