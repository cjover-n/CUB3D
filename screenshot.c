/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:53:19 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/07 21:11:29 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screenshot_header(t_structcub *cub, int o, unsigned char *bmp, int size)
{
	bmp[0] = (unsigned char) 'B';
	bmp[1] = (unsigned char) 'M';
	screenshot_bit(bmp + 2, size);
	bmp[10] = (unsigned char) 54;
	bmp[14] = (unsigned char) 40;
	screenshot_bit(bmp + 18, cub->screen.width);
	screenshot_bit(bmp + 22, cub->screen.height);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)32;
	write(o, bmp, 54);
}

void	screenshot_bit(unsigned char *src, int nb)
{
	src[0] = (unsigned char)(nb);
	src[1] = (unsigned char)(nb >> 8);
	src[2] = (unsigned char)(nb >> 16);
	src[3] = (unsigned char)(nb >> 24);
}

void	screenshot_draw(t_structcub *cub, int o)
{
	int				y;
	int				x;
	unsigned int	*clr;
	int				bpp;

	bpp = (cub->screen.bit / 8);
	y = cub->screen.height - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < cub->screen.width)
		{
			clr = &cub->screen.addr_img[(cub->screen.size_line * y) + x * bpp];
			if (write(o, clr, bpp) < 0)
			{
				printf("Error haciendo la captura\n");
				exit(1);
			}
		}
		y--;
	}
}

void	screenshot(t_structcub *cub)
{
	static unsigned char	bmp[54];
	int						o;
	int						size;

	o = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0744);
	if (o < 0)
		printf("Error creando screenshot\n");
	size = 54 + 4 * (cub->screen.width * cub->screen.height);
	screenshot_header(cub, o, bmp, size);
	screenshot_draw(cub, o);
	close(o);
}
