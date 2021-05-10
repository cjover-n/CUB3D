/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:01:39 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/10 21:58:40 by cjover-n         ###   ########.fr       */
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

void	file_checker(char **argv)
{
	char	*tmp;

	if ((ft_strchr(argv[1], '.')))
	{
		tmp = ft_strchr(argv[1], '.');
		if (!(*++tmp == 'c' && *++tmp == 'u' && *++tmp == 'b' && *++tmp == '\0'))
			error_handler1(12);
	}
	else
		error_handler1(13);
}
