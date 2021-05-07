/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:56:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/07 20:13:07 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution_parser(char *line, t_structcub *cub)
{
	int		i;

	i = 0;
	if (!cub->screen.width && !cub->screen.height)
	{
		while (!(ft_isdigit(line[i])))
			i++;
		if (ft_isdigit(line[i]))
		{
			cub->screen.width = ft_atoi(&line[i]);
			if (cub->screen.width > 2560)
				cub->screen.width = 2560;
			i = ft_numlen(cub->screen.width) + i + 1;
			if (ft_isdigit(line[i]) == 1)
			{
				cub->screen.height = ft_atoi(&line[i]);
				if (cub->screen.height > 1395)
					cub->screen.height = 1395;
				i = ft_numlen(cub->screen.width) + ft_numlen(cub->screen.height) \
					+ 3;
				if (line[i] != '\n' && line[i] != '\0' )
					error_handler1(16);
			}
		}
		else
			error_handler1(3);
	}
	else
		error_handler1(18);
}

char	*texture_parser(t_structcub *cub, char *arr)
{
	(void)cub;
	while (*arr != '.' && *arr != '\0')
		arr++;
	if (*arr != '.')
	{
		error_handler1(5);
		return (NULL);
	}
	return (ft_strdup(arr));
}

unsigned int	color_parser(char *line)
{
	int				i;
	int				x;
	int				color[3];

	x = 0;
	i = space_checker(line, 1);
	while (ft_isdigit(line[i]))
	{
		if (ft_isdigit(line[i]))
		{
			color[x] = ft_atoi(line + i);
			if (!ft_isdigit(line[i + 1]))
				error_handler1(24);
			if (rgb_range(color[x]) == 0)
				error_handler1(25);
			i += ft_numlen(color[x]);
		}
		else
			error_handler1(26);
		if (line[i] == ',')
			x++;
		i += (line[i] != '\0');
	}
	if (x != 2)
		error_handler1(27);
	return (create_trgb(0, color[0], color[1], color[2]));
}
