/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:25:11 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:35:22 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_check1(t_structcub *cub, char *line, int i)
{
	if (i == 0)
	{
		cub->t_north = ft_strdup(texture_parser(cub, line));
		cub->img = ft_strnstr(cub->t_north, ".xpm", ft_strlen(cub->t_north));
		if (!cub->img)
			error_handler1(19);
		cub->nf = 1;
	}
	if (i == 1)
	{
		cub->t_east = ft_strdup(texture_parser(cub, line));
		cub->img = ft_strnstr(cub->t_east, ".xpm", ft_strlen(cub->t_east));
		if (!cub->img)
			error_handler1(20);
		cub->ef = 1;
	}
	if (i == 2)
	{
		cub->t_south = ft_strdup(texture_parser(cub, line));
		cub->img = ft_strnstr(cub->t_south, ".xpm", ft_strlen(cub->t_south));
		if (!cub->img)
			error_handler1(21);
		cub->sf = 1;
	}
	texture_check2(cub, i, line);
}

void	texture_check2(t_structcub *cub, int i, char *line)
{
	if (i == 3)
	{
		cub->t_west = ft_strdup(texture_parser(cub, line));
		cub->img = ft_strnstr(cub->t_west, ".xpm", ft_strlen(cub->t_west));
		if (!cub->img)
			error_handler1(22);
		cub->wf = 1;
	}
	if (i == 4)
	{
		cub->t_sprite = ft_strdup(texture_parser(cub, line));
		cub->img = ft_strnstr(cub->t_sprite, ".xpm", ft_strlen(cub->t_sprite));
		if (!cub->img)
			error_handler1(23);
		cub->pf = 1;
	}
}

void	texture_floor_ceiling(t_structcub *cub)
{
	while (cub->side < cub->start_copy)
		cub->screen.addr_img[cub->side++ *cub->screen.width
			+ cub->x] = cub->c_hex;
	cub->side = cub->draw_end;
	while (cub->side < cub->screen.height)
		cub->screen.addr_img[cub->side++ *cub->screen.width
			+ cub->x] = cub->f_hex;
}

int	something_strange(t_structcub *cub, char *line)
{
	int	ln;

	ln = cub->l;
	if ((!(ft_strnstr(line, "R ", ln)) && !(ft_strnstr(line, "NO ", ln)) \
		&& !(ft_strnstr(line, "EA ", ln)) && !(ft_strnstr(line, "SO ", ln)) \
		&& !(ft_strnstr(line, "WE ", ln)) && !(ft_strnstr(line, "C ", ln)) \
		&& !(ft_strnstr(line, "F ", ln)) && !(ft_strnstr(line, "S ", ln))))
		return (1);
	else
		return (0);
}

void	repeating_values(t_structcub *cub, char *line)
{
	int	ln;

	ln = cub->l;
	if (((ft_strnstr(line, "R ", ln) && cub->rf) || (ft_strnstr(line, "NO ", ln) && cub->nf) \
	|| (ft_strnstr(line, "EA ", ln) && cub->ef) || (ft_strnstr(line, "SO ", ln) && cub->sf) \
	|| (ft_strnstr(line, "WE ", ln) && cub->wf) || (ft_strnstr(line, "C ", ln) && cub->cf) \
	|| (ft_strnstr(line, "F ", ln) && cub->ff) \
	|| (ft_strnstr(line, "S ", ln) && cub->pf)))
		error_handler1(31);
}
