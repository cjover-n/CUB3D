/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:01:39 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/29 23:03:58 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	space_checker(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

int	rgb_range(int cr)
{
	if (cr < 0 || cr > 255)
		return (0);
	else
		return (1);
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
