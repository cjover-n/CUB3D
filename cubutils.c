/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:01:39 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/19 23:32:46 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	space_checker(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

void	ft_realloc(t_structcub *cub)
{
	char	*tmp;

	if (cub->spr.found * 2 > (int)cub->buf)
	{
		tmp = malloc(cub->buf += 4 * sizeof(double));
		ft_strcpy(tmp, cub->spr.array);
		free(cub->spr.array);
		cub->spr.array = tmp;
	}
}
