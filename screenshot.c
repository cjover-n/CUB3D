/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:13:24 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 17:29:43 by cjover-n         ###   ########lyon.fr   */
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
	int				*color;
	int				bpp;

	bpp = (cub->screen.bit / 8);
	y = cub->screen.height - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < cub->screen.width)
		{
			color = (int *)&cub->screen.addr_img[(cub->screen.size_line * y) + x * bpp];
			if (write(o, color, bpp) < 0)
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

	o = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (o < 0)
		printf("Error creando screenshot\n");
	size = 54 + cub->screen.width * cub->screen.height;
	screenshot_header(cub, o, bmp, size);
	screenshot_draw(cub, o);
	close(o);
}
