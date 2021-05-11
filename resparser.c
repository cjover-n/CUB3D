/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:22:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/11 14:23:16 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution_parser1(char *line, t_structcub *cub)
{
	int		i;

	i = 0;
	if (!cub->screen.width && !cub->screen.height)
	{
		while (!(ft_isdigit(line[i])))
			i++;
		if (ft_isdigit(line[i]))
			resolution_parser2(line, cub, i);
		else
			error_handler1(3);
	}
	else
		error_handler1(18);
}

void	resolution_parser2(char *line, t_structcub *cub, int i)
{
	cub->screen.width = ft_atoi(&line[i]);
	height_width_check(cub, 0);
	i = ft_numlen(cub->screen.width) + i + 1;
	if (ft_isdigit(line[i]) == 1)
	{
		cub->screen.height = ft_atoi(&line[i]);
		height_width_check(cub, 1);
		i = ft_numlen(cub->screen.width) \
			+ ft_numlen(cub->screen.height) + 3;
		if (line[i] == '\0')
			return ;
		if (!ft_isdigit(line[i]))
			error_handler1(16);
	}
}
