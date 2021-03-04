/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/03/03 00:12:47 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites(t_structcub *cub)
{
	t_spritelist	*spritelist;
	//t_structsprite	*sprite;
	int				i;

	i = 0;

	spritedistance(cub);
	sortsprites(cub);
	while (i < cub->spr.found)
	spritelist = spriteiter(cub, cub->spr.spriteorder[i]);
	spriteproject(cub);
	spritedraw(cub);
}

void	spriteproject(t_structcub *cub)
{
	int		i;

	i = 0;
	while (i < cub->spr.found)
	{
		cub->spr.sprite_x = (spriteiter(cub, i))->posx - cub->pos_x;
		cub->spr.sprite_y = (spriteiter(cub, i))->posy - cub->pos_y;
		cub->spr.invdet = 1.0 / (cub->plane_x * cub->dir_y - cub->dir_x *
			cub->plane_y);
		cub->spr.trans_x = cub->spr.invdet * (cub->dir_y *
			cub->spr.sprite_x - cub->dir_x * cub->spr.sprite_y);
		cub->spr.trans_y = cub->spr.invdet * ((-1 * cub->plane_y) *
			cub->spr.sprite_x + cub->plane_x * cub->spr.sprite_y);
		cub->spr.sprscreenx = (int)(cub->screen.width / 2) * (1 + cub->spr.trans_x / cub->spr.trans_y);
		cub->spr.sprheight = abs((int)(cub->screen.height / cub->spr.trans_y));
		cub->spr.drawstart_y = (-1 * cub->spr.sprheight) / 2 + cub->screen.height / 2;
		cub->spr.drawstart_y < 0 ? cub->spr.drawstart_y = 0 : 0;
		cub->spr.drawend_y = cub->spr.sprheight / 2 + cub->screen.height / 2;
		cub->spr.drawend_y >= cub->screen.height ? cub->spr.drawend_y = cub->screen.height - 1 : 0;
		cub->spr.sprwidth = abs((int)(cub->screen.height / cub->spr.trans_y));
		cub->spr.drawstart_x = -1 * cub->spr.sprwidth / 2 + cub->spr.sprscreenx;
		cub->spr.drawstart_x < 0 ? cub->spr.drawstart_x = 0 : 0;
		cub->spr.drawend_x = cub->spr.sprwidth / 2 + cub->spr.sprscreenx;
		cub->spr.drawend_x > cub->screen.width ? cub->spr.drawend_x = cub->screen.width - 1 : 0;
		spritedraw(cub);
	}
}

void	spritedraw(t_structcub *cub)
{
	int		stripe;
	int		texx;
	int		texy;
	int		y;
	int		d;

	int texwidth = 64;
	int	texheight = 64;
	stripe = cub->spr.drawstart_x;
	while (stripe < cub->spr.drawend_x)
	{
		texx = (int)(256 * (stripe - ((-1) * cub->spr.sprwidth / 2 + cub->spr.sprscreenx)) * texwidth / cub->spr.sprwidth) / 256;
		if (cub->spr.trans_y > 0 && stripe > 0 && stripe < cub->screen.width && cub->spr.trans_y < cub->spr.zbuffer[stripe])
		{
			y = cub->spr.drawstart_y;
			while (y < cub->spr.drawend_y)
			{
				d = y * 256 - cub->screen.height * 128 + cub->spr.s_height * 128;
				texy = ((d * texheight) / cub->spr.s_height) / 256;
				cub->spr.color = cub->spr.addr_sprite[cub->spr.sprwidth * texy + texx];
				//Uint32 color = texture[             sprite[spriteOrder[i]].texture][texWidth * texY + texX];
			}
		}
	}
}

void	spritedistance(t_structcub *cub)
{
	int		i;

	i = 0;
	while (i < cub->spr.found)
	{
		cub->spr.spriteorder[i] = i;
		cub->spr.spritedistance[i] = sqrt(pow(cub->pos_x -
			(spriteiter(cub, i))->posx, 2.0) + pow(cub->pos_y -
			(spriteiter(cub, i))->posy, 2.0));
	}
}

t_spritelist	*spriteiter(t_structcub *cub, int listmember)
{
	t_spritelist	*ptr;
	int				i;

	i = 0;
	ptr = cub->spritelist;
	while (i++ < listmember)
		ptr = ptr->next;
	return (ptr);
}

void	sortsprites(t_structcub *cub)
{
	int			i;
	double		distance[cub->spr.found];
	int			foo;

	i = 0;
	while (cub->spr.found > 1 && i < cub->spr.found - 1)
	{
		if (distance[i] < distance[i + 1])
		{
			foo = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = foo;
			foo = cub->spr.spriteorder[i];
			cub->spr.spriteorder[i] = cub->spr.spriteorder[i + 1];
			cub->spr.spriteorder[i + 1] = foo;
			i = -1;
		}
	}
}

