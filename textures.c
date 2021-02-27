/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:01:02 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/27 20:53:38 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_structcub *cub)
{
	cub->tex.t_north = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_north, &cub->tex.t_n_width, &cub->tex.t_n_height);
	cub->tex.addr_north = (unsigned int *)mlx_get_data_addr(cub->tex.t_north,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->tex.t_east = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_east, &cub->tex.t_e_width, &cub->tex.t_e_height);
	cub->tex.addr_east = (unsigned int *)mlx_get_data_addr(cub->tex.t_east,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->tex.t_south = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_south, &cub->tex.t_s_width, &cub->tex.t_s_height);
	cub->tex.addr_south = (unsigned int *)mlx_get_data_addr(cub->tex.t_south,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->tex.t_west = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_west, &cub->tex.t_w_width, &cub->tex.t_w_height);
	cub->tex.addr_west = (unsigned int *)mlx_get_data_addr(cub->tex.t_west,
		&cub->bit, &cub->size_line, &cub->endian);
	cub->spr.t_sprite = mlx_xpm_file_to_image(cub->screen.mlx_ptr,
		cub->t_sprite, &cub->spr.s_width, &cub->spr.s_height);
	cub->spr.addr_sprite = (unsigned int *)mlx_get_data_addr(cub->spr.t_sprite,
		&cub->bit, &cub->size_line, &cub->endian);
}

/*
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
		cub->screen.addr_img[cub->start_copy++ *
		cub->screen.width + cub->x] = cub->color;
}
*/

void	textures(t_structcub *cub)
{
	if (cub->side == 0)
		cub->tex.wallx = cub->pos_y + cub->perpwalldist * cub->raydiry;
	else
		cub->tex.wallx = cub->pos_x + cub->perpwalldist * cub->raydirx;
	cub->tex.wallx -= floor(cub->tex.wallx);
	cub->tex.tex_x = (int)(cub->tex.wallx * (double)cub->tex.active_width);
	if (cub->side == 0 && cub->raydirx > 0)
		cub->tex.tex_x = cub->tex.active_width - cub->tex.tex_x - 1;
	if (cub->side == 1 && cub->raydiry < 0)
		cub->tex.tex_x = cub->tex.active_width - cub->tex.tex_x - 1;
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
		cub->tex.active = cub->tex.addr_east;
		cub->tex.active_width = cub->tex.t_e_width;
		cub->tex.active_height = cub->tex.t_e_height;
	}
	else if (cub->side == 0 && cub->raydirx < 0)
	{
		cub->tex.active = cub->tex.addr_west;
		cub->tex.active_width = cub->tex.t_w_width;
		cub->tex.active_height = cub->tex.t_w_height;
	}
	else if (cub->side == 1 && cub->raydiry > 0)
	{
		cub->tex.active = cub->tex.addr_south;
		cub->tex.active_width = cub->tex.t_s_width;
		cub->tex.active_height = cub->tex.t_s_height;
	}
	else if (cub->side == 1 && cub->raydiry < 0)
	{
		cub->tex.active = cub->tex.addr_north;
		cub->tex.active_width = cub->tex.t_n_width;
		cub->tex.active_height = cub->tex.t_n_height;
	}
	//plain_color(cub);
}

void	texture_color_selector(t_structcub *cub)
{
	int		y;

	y = cub->draw_start;
	cub->tex.step = 1.0 * cub->tex.active_height / cub->lineheight;
	cub->tex.tex_pos = (cub->draw_start - cub->screen.height /
		2 + cub->lineheight / 2) * cub->tex.step;
	while (y < cub->draw_end)
	{
		cub->tex.tex_y = (int)cub->tex.tex_pos & (cub->tex.active_height - 1);
		cub->tex.tex_pos += cub->tex.step;
		cub->color = cub->tex.active[cub->tex.active_width *
			cub->tex.tex_y + cub->tex.tex_x];
		cub->screen.addr_img[y * cub->screen.width + cub->x] = cub->color;
		y++;
	}
}

void	texture_floor_ceiling(t_structcub *cub)
{
	while (cub->side < cub->start_copy)
		cub->screen.addr_img[cub->side++ * cub->screen.width +
		cub->x] = cub->c_hex;
	cub->side = cub->draw_end;
	while (cub->side < cub->screen.height)
		cub->screen.addr_img[cub->side++ * cub->screen.width +
		cub->x] = cub->f_hex;
}
