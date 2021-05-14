/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:29:13 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	gnl(char *line, int fd, t_structcub *cub)
{
	cub->gnl = get_next_line(fd, &line);
	while (cub->gnl > 0)
	{
		cub->isline = 0;
		if (!everything_ok(cub) && !ft_strnstr(line, "111", 3) \
			&& cub->map_start < 1)
			line_checker(line, cub);
		else
		{
			cub->map_start = 1;
			if (line[0] != '\0')
			{
				cub->isline = is_map_line(line, cub);
				if (!cub->isline)
					error_handler1(7);
				else
					get_map(cub, line, &cub->map_buff);
			}
		}
		free(line);
		cub->gnl = get_next_line(fd, &line);
	}
	gnl_ch(line, cub);
	free(line);
}

void	gnl_ch(char *line, t_structcub *cub)
{
	if (cub->gnl < 0)
		error_handler1(2);
	else if (cub->gnl == 0)
	{
		cub->isline = 0;
		cub->isline = is_map_line(line, cub);
		if (!cub->isline && *line != '\0')
			error_handler1(7);
		else
			get_map(cub, line, &cub->map_buff);
		cub->map = ft_split(cub->map_buff, '.');
		if (flood_check(cub, cub->pos_y, cub->pos_x) == 1)
			error_handler1(11);
		free(cub->map_buff);
	}
}

void	line_init(char *line, t_structcub *cub)
{
	cub->z = 0;
	while (ft_isspace(line[cub->z]))
		cub->z++;
	cub->l = ft_strlen(line);
	repeating_values(cub, line);
}

void	line_checker(char *line, t_structcub *cub)
{
	line_init(line, cub);
	if (line[cub->z] == 'R' && ft_strnstr(line, "R ", cub->l) && !cub->rf)
		resolution_parser1(line, cub);
	else if (line[cub->z] == 'N' && ft_strnstr(line, "NO ", cub->l) && !cub->nf)
		texture_check1(cub, line, 0);
	else if (line[cub->z] == 'E' && ft_strnstr(line, "EA ", cub->l) && !cub->ef)
		texture_check1(cub, line, 1);
	else if (line[cub->z] == 'S' && ft_strnstr(line, "SO ", cub->l) && !cub->sf)
		texture_check1(cub, line, 2);
	else if (line[cub->z] == 'W' && ft_strnstr(line, "WE ", cub->l) && !cub->wf)
		texture_check1(cub, line, 3);
	else if (line[cub->z] == 'S' && ft_strnstr(line, "S ", cub->l) && !cub->pf)
		texture_check1(cub, line, 4);
	else if (line[cub->z] == 'F' && ft_strnstr(line, "F ", cub->l) && !cub->ff)
		color_asign(cub, line, 0);
	else if (line[cub->z] == 'C' && ft_strnstr(line, "C ", cub->l) && !cub->cf)
		color_asign(cub, line, 1);
	else if (line[cub->z++] == '\0')
		return ;
	else
		map_error(cub);
	if (something_strange(cub, line))
		error_handler1(30);
}

void	map_error(t_structcub *cub)
{
	if (!cub->rf && cub->nf && cub->sf && cub->wf \
		&& cub->ef && cub->cf && cub->ff && cub->pf)
		error_handler1(29);
	else if (cub->rf && !cub->nf && cub->sf && cub->wf \
		&& cub->ef && cub->cf && cub->ff && cub->pf)
		error_handler1(19);
	else if (cub->rf && cub->nf && !cub->sf && cub->wf \
		&& cub->ef && cub->cf && cub->ff && cub->pf)
		error_handler1(21);
	else if (cub->rf && cub->nf && cub->sf && !cub->wf \
		&& cub->ef && cub->cf && cub->ff && cub->pf)
		error_handler1(22);
	else if (cub->rf && cub->nf && cub->sf && cub->wf \
		&& !cub->ef && cub->cf && cub->ff && cub->pf)
		error_handler1(20);
	else if (cub->rf && cub->nf && cub->sf && cub->wf \
		&& cub->ef && (!cub->cf || !cub->ff) && cub->pf)
		error_handler1(24);
	else if (cub->rf && cub->nf && cub->sf && cub->wf \
		&& cub->ef && cub->cf && cub->ff && !cub->pf)
		error_handler1(23);
	else
		return ;
}
