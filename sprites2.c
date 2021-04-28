/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/28 14:31:18 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spriteproject(t_structcub *cub)
{
	int		i;

	i = -1;
	while (++i < cub->spr.found)
	{
		if (cub->map[(int)cub->spr.y[i]][(int)cub->spr.x[i]] == '2')
		{
			cub->spr.sprite_x = cub->spr.x[i] - cub->pos_x;
			cub->spr.sprite_y = cub->spr.y[i] - cub->pos_y;
			cub->spr.invdet = 1.0 / (cub->plane_x * cub->dir_y \
					- cub->dir_x * cub->plane_y);
			cub->spr.trans_x = cub->spr.invdet * (cub->dir_y \
					* cub->spr.sprite_x - cub->dir_x * cub->spr.sprite_y);
			cub->spr.trans_y = cub->spr.invdet * (-cub->plane_y \
					* cub->spr.sprite_x + cub->plane_x * cub->spr.sprite_y);
			cub->spr.sprscreenx = (int)((cub->screen.width / 2) \
					* (1 + cub->spr.trans_x / cub->spr.trans_y));
			cub->spr.sprheight = abs((int)(cub->screen.height \
						/ cub->spr.trans_y));
			cub->spr.drawstart_y = (-cub->spr.sprheight / 2)
				+ (cub->screen.height / 2);
			spritecalc(cub);
			spritedraw(cub);
		}
	}
}

void	spritecalc(t_structcub *cub)
{
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
}

void	spritedraw(t_structcub *cub)
{
	while (cub->spr.stripe < cub->spr.drawend_x)
	{
		cub->spr.texx = (int)(((cub->spr.s_height * 4) * (cub->spr.stripe \
					- ((-cub->spr.sprwidth / 2) + cub->spr.sprscreenx))) \
					* cub->spr.s_width / cub->spr.sprwidth) \
					/ (cub->spr.s_height * 4);
		if (cub->spr.trans_y > 0 && cub->spr.stripe > 0 && cub->spr.stripe
			< cub->screen.width && cub->spr.trans_y
			< cub->spr.zbuffer[cub->spr.stripe])
		{
			cub->spr.p = cub->spr.drawstart_y;
			spritedraw_while(cub);
		}
		cub->spr.stripe++;
	}
}

void	spritedraw_while(t_structcub *cub)
{
	char	*dst;

	while (cub->spr.p < cub->spr.drawend_y)
	{
		cub->spr.d = (cub->spr.p) * (cub->spr.s_height * 4) - cub->screen.height \
			* (cub->spr.s_height * 2) + cub->spr.sprheight \
			* (cub->spr.s_height * 2);
		cub->spr.texy = ((cub->spr.d * cub->spr.s_height) / cub->spr.sprheight) \
			/ (cub->spr.s_height * 4);
		cub->spr.color = cub->spr.addr_sprite[(cub->size_line[4] \
				/ 4) *cub->spr.texy + cub->spr.texx];
		if ((cub->spr.color & BLACK) != 0)
			cub->screen.addr_img[cub->spr.p * cub->screen.width \
				+ cub->spr.stripe] = cub->spr.color;
		if ((cub->spr.color != TRANSPARENCY) && (cub->spr.color != 0))
		{
			dst = (char *)cub->screen.addr_img + (cub->spr.p \
					* cub->screen.size_line + cub->spr.stripe \
					* (cub->screen.bit / 8));
			*(unsigned int *)dst = cub->spr.color;
		}
		cub->spr.p++;
	}
}
