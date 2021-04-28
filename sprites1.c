/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:39:01 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/28 14:42:05 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites(t_structcub *cub)
{
	int	i;

	i = -1;
	while (i++ < cub->spr.found)
		cub->spr.spritedist[i] = sqrt(pow(cub->pos_x - cub->spr.x[i], 2.0)
				+ pow(cub->pos_y - cub->spr.y[i], 2.0));
	sortsprites(cub);
	spriteproject(cub);
}

void	get_sprites(t_structcub *cub)
{
	int		i;
	int		r;
	int		c;

	i = 0;
	r = -1;
	cub->spr.spritedist = malloc(sizeof(double) * cub->spr.found);
	cub->spr.x = malloc(sizeof(double) * cub->spr.found);
	cub->spr.y = malloc(sizeof(double) * cub->spr.found);
	while (++r < cub->line_counter - 1)
	{
		c = -1;
		while (++c < cub->map_len)
		{
			if (cub->map[r][c] == 50)
			{
				cub->spr.x[i] = c + 0.5;
				cub->spr.y[i] = r + 0.5;
				i++;
			}
		}
	}
}

void	sortsprites(t_structcub *cub)
{
	int			i;
	double		tmp;
	int			j;

	i = -1;
	while (++i < cub->spr.found)
	{
		j = -1;
		while (++j < cub->spr.found - i - 1)
		{
			if (cub->spr.spritedist[j] < cub->spr.spritedist[j + 1])
			{
				tmp = cub->spr.x[j];
				cub->spr.x[j] = cub->spr.x[j + 1];
				cub->spr.x[j + 1] = tmp;
				tmp = cub->spr.y[j];
				cub->spr.y[j] = cub->spr.y[j + 1];
				cub->spr.y[j + 1] = tmp;
				tmp = cub->spr.spritedist[j];
				cub->spr.spritedist[j] = cub->spr.spritedist[j + 1];
				cub->spr.spritedist[j + 1] = tmp;
			}
		}
	}
}
