/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:53:19 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/10 14:21:32 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screenshot_header(t_structcub *cub, int o, int size)
{
	char					bmp[54];

	ft_bzero(bmp, 54);
	bmp[0] = 'B';
	bmp[1] = 'M';
	screenshot_bit(bmp + 2, size);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	screenshot_bit(bmp + 18, cub->screen.width);
	screenshot_bit(bmp + 22, -cub->screen.height);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)32;
	write(o, bmp, 54);
}

void	screenshot_bit(char *src, int nb)
{
	src[0] = (unsigned char)nb;
	src[1] = (unsigned char)(nb >> 8);
	src[2] = (unsigned char)(nb >> 16);
	src[3] = (unsigned char)(nb >> 24);
}

void	screenshot_draw(t_structcub *cub, int o)
{
	char	*pixels_image;
	int		i;

	i = 0;
	pixels_image = (char *)cub->screen.addr_img;
	while (i < cub->screen.width)
		write(o, &pixels_image[i++ *(cub->screen.size_line * 4)], \
		cub->screen.width * 16);
}

void	screenshot(t_structcub *cub)
{
	int						o;
	int						size;

	o = open("screenshot.bmp", O_WRONLY | O_CREAT | S_IRWXU \
		| O_TRUNC | O_APPEND);
	if (o < 0)
		printf("Error creando screenshot\n");
	size = 54 + (cub->screen.width * cub->screen.height * 4);
	screenshot_header(cub, o, size);
	screenshot_draw(cub, o);
	close(o);
	printf("Captura de pantalla realizada correctamente.");
	exit(1);
}
