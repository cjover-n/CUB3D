/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/25 20:13:20 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites(t_structcub *cub)
{
	//cub->spr.vmovescreen = (int)(0.0 / cub->spr.trans_y);
	spritedistance(cub);
	sortsprites(cub);
	spriteproject(cub);
}
/*
void	spritewhere(t_structcub *cub, int found, int i)
{
	ft_realloc(cub);
	cub->spr.posx = (double)i;
	cub->spr.posy = (double)cub->line_counter;
	cub->spr.array[(found * 2) - 2] = cub->spr.posx;
	cub->spr.array[(found * 2) - 1] = cub->spr.posy;
}
*/

void	get_sprites(t_structcub *cub)
{
	int		i;
	int		r;
	int		c;

	i = 0;
	r = -1;
	cub->spr.spritedistance = malloc(sizeof(double) * cub->spr.found);
	cub->spr.x = malloc(sizeof(double) * cub->spr.found);
	cub->spr.y = malloc(sizeof(double) * cub->spr.found);
	while (++r < cub->line_counter - 1)
	{
		c = -1;
		while (++c < cub->map_len)
		{
			//ft_printf("ESTO ES LO QUE VALE MAP RC: %s", cub->map[r]);
			if (cub->map[r][c] == 50)
			{
				cub->spr.x[i] = r + 0.5;
				cub->spr.y[i] = c + 0.5;
				i++;
			}
		}
	}
}

void	spriteproject(t_structcub *cub)
{
	int		i;

	i = 0;
	while (i < cub->spr.found)
	{
		if (cub->map[(int)cub->spr.x[i]][(int)cub->spr.y[i]] == '2')
		{
			cub->spr.sprite_y = cub->spr.x[i] - cub->pos_y;
			cub->spr.sprite_x = cub->spr.y[i] - cub->pos_x;
			//aqui empieza projection_spr de Elena
			cub->spr.invdet = 1.0 / (cub->plane_x * cub->dir_y
					- cub->dir_x * cub->plane_y);
			cub->spr.trans_x = cub->spr.invdet * (cub->dir_y
					* cub->spr.sprite_x - cub->dir_x * cub->spr.sprite_y);
			cub->spr.trans_y = cub->spr.invdet * (-cub->plane_y * cub->spr.sprite_x + cub->plane_x * cub->spr.sprite_y);
			cub->spr.sprscreenx = (int)((cub->screen.width / 2) * (1 + cub->spr.trans_x / cub->spr.trans_y));
			cub->spr.sprheight = abs((int)(cub->screen.height / cub->spr.trans_y));
			cub->spr.drawstart_y = (-cub->spr.sprheight / 2) + (cub->screen.height / 2);
			if (cub->spr.drawstart_y < 0)
				cub->spr.drawstart_y = 0;
			cub->spr.drawend_y = (cub->spr.sprheight / 2) + (cub->screen.height / 2);
			if (cub->spr.drawend_y >= cub->screen.height)
				cub->spr.drawend_y = cub->screen.height - 1;
			cub->spr.sprwidth = abs((int)(cub->screen.height / cub->spr.trans_y));
			cub->spr.drawstart_x = (-cub->spr.sprwidth / 2) + cub->spr.sprscreenx;
			if (cub->spr.drawstart_x < 0)
				cub->spr.drawstart_x = 0;
			cub->spr.drawend_x = cub->spr.sprwidth / 2 + cub->spr.sprscreenx;
			if (cub->spr.drawend_x >= cub->screen.width)
				cub->spr.drawend_x = cub->screen.width - 1;
			cub->spr.stripe = cub->spr.drawstart_x;
			//aqui termina
			spritedraw(cub);
		}
		i++;
	}
}

void	spritedraw(t_structcub *cub)
{
	int				texx;
	int				texy;
	int				y;
	int				d;
	char	*dst;

	while (cub->spr.stripe < cub->spr.drawend_x)
	{
		//texx = (int)(256 * (cub->spr.stripe - (-cub->spr.sprwidth / 2 + cub->spr.sprscreenx)) * cub->spr.s_width / cub->spr.sprwidth) / 256;
		texx = (int)(((cub->spr.s_height * 4) * (cub->spr.stripe - ((-cub->spr.sprwidth / 2) + cub->spr.sprscreenx))) * cub->spr.s_width / cub->spr.sprwidth) / (cub->spr.s_height * 4);
		if (cub->spr.trans_y > 0 && cub->spr.stripe > 0 && cub->spr.stripe < cub->screen.width && cub->spr.trans_y < cub->spr.zbuffer[cub->spr.stripe])
		{
			y = cub->spr.drawstart_y;
			while (y < cub->spr.drawend_y)
			{
				//d = (y - cub->spr.vmovescreen) * 256 - cub->screen.height * 128 + cub->spr.sprheight * 128;
				d = (y) * (cub->spr.s_height * 4) - cub->screen.height * (cub->spr.s_height * 2) + cub->spr.sprheight * (cub->spr.s_height * 2);
				texy = ((d * cub->spr.s_height) / cub->spr.sprheight) / (cub->spr.s_height * 4);
				cub->spr.color = cub->spr.addr_sprite[(cub->size_line[4] / 4) *texy + texx];

				if ((cub->spr.color & BLACK) != 0)
					cub->screen.addr_img[y * cub->screen.width + cub->spr.stripe] = cub->spr.color;
				if (cub->spr.color != 0)
				{
					dst = (char *)cub->screen.addr_img + (y * cub->screen.size_line + cub->spr.stripe * (cub->screen.bit / 8));
					*(unsigned int *)dst = cub->spr.color;
 				}
				y++;
			}
		}
		cub->spr.stripe++;
	}
}

void	spritedistance(t_structcub *cub)
{
	int i;

	i = 0;
	while (i < cub->spr.found)
	{
		//cub->spr.spriteorder[i] = i;
		cub->spr.spritedistance[i] = sqrt(pow(cub->pos_x - cub->spr.x[i], 2.0) + pow(cub->pos_y - cub->spr.y[i], 2.0));
		i++;
	}
}

void	sortsprites(t_structcub *cub)
{
	int			i;
	int			tmp;
	int			j;

	i = 0;
	while (i < cub->spr.found)
	{
		j = 0;
		while (j < cub->spr.found - i - 1)
		{
			if (cub->spr.spritedistance[j] < cub->spr.spritedistance[j + 1])
			{
				tmp = cub->spr.x[j];
				cub->spr.x[j] = cub->spr.x[j + 1];
				cub->spr.x[j + 1] = tmp;
				tmp = cub->spr.y[j];
				cub->spr.y[j] = cub->spr.y[j + 1];
				cub->spr.y[j + 1] = tmp;
				tmp = cub->spr.spritedistance[j];
				cub->spr.spritedistance[j] = cub->spr.spritedistance[j + 1];
				cub->spr.spritedistance[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
