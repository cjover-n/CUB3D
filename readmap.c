/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:00:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/12 19:16:07 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	readmap(char *cubmap, t_structcub *cub)
{
	char	*line;
	int		fd;

	fd = open(cubmap, O_RDONLY, S_IRUSR);
	if (fd >= 3)
	{
		line = NULL;
		gnl(line, fd, cub);
		close(fd);
		if (cub->spr.found > 0)
			get_sprites(cub);
		free(line);
	}
}

void	gnl(char *line, int fd, t_structcub *cub)
{
	int	gnl;

	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		cub->isline = 0;
		if (!everything_ok(cub) && ft_strncmp(line, "111", 3) != 0 \
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
		gnl = get_next_line(fd, &line);
	}
	gnl_ch(gnl, line, cub);
	free(line);
}

void	gnl_ch(int gnl, char *line, t_structcub *cub)
{
	if (gnl < 0)
		error_handler1(2);
	else if (gnl == 0)
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

void	line_checker(char *line, t_structcub *cub)
{
	int		len;
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	len = ft_strlen(line);
	if (line[i] == 'R' && ft_strchr(line, 'R') && !cub->r_flag)
		resolution_parser1(line, cub);
	else if (line[i] == 'N' && ft_strnstr(line, "NO", len) && !cub->n_flag)
		texture_check1(cub, line, 0);
	else if (line[i] == 'E' && ft_strnstr(line, "EA", len) && !cub->e_flag)
		texture_check1(cub, line, 1);
	else if (line[i] == 'S' && ft_strnstr(line, "SO", len) && !cub->s_flag)
		texture_check1(cub, line, 2);
	else if (line[i] == 'W' && ft_strnstr(line, "WE", len) && !cub->w_flag)
		texture_check1(cub, line, 3);
	else if (line[i] == 'S' && ft_strchr(line, 'S') && !cub->s_flag)
		texture_check1(cub, line, 4);
	else if (line[i] == 'F' && ft_strchr(line, 'F') && !cub->f_flag)
		color_asign(cub, line, 0);
	else if (line[i] == 'C' && ft_strchr(line, 'C') && !cub->c_flag)
		color_asign(cub, line, 1);
	else if (line[i++] == '\0')
		return ;
	else
		map_error(cub);
	if (something_strange(cub, line, len))
		error_handler1(28);
}

void	map_error(t_structcub *cub)
{
	if (!cub->r_flag && cub->n_flag && cub->s_flag && cub->w_flag \
		&& cub->e_flag && cub->c_flag && cub->f_flag && cub->spr_flag)
		error_handler1(29);
	if (cub->r_flag && !cub->n_flag && cub->s_flag && cub->w_flag \
		&& cub->e_flag && cub->c_flag && cub->f_flag && cub->spr_flag)
		error_handler1(19);
	if (cub->r_flag && cub->n_flag && !cub->s_flag && cub->w_flag \
		&& cub->e_flag && cub->c_flag && cub->f_flag && cub->spr_flag)
		error_handler1(21);
	if (cub->r_flag && cub->n_flag && cub->s_flag && !cub->w_flag \
		&& cub->e_flag && cub->c_flag && cub->f_flag && cub->spr_flag)
		error_handler1(22);
	if (cub->r_flag && cub->n_flag && cub->s_flag && cub->w_flag \
		&& !cub->e_flag && cub->c_flag && cub->f_flag && cub->spr_flag)
		error_handler1(20);
	if (cub->r_flag && cub->n_flag && cub->s_flag && cub->w_flag \
		&& cub->e_flag && (!cub->c_flag || !cub->f_flag) && cub->spr_flag)
		error_handler1(24);
	if (cub->r_flag && cub->n_flag && cub->s_flag && cub->w_flag \
		&& cub->e_flag && cub->c_flag && cub->f_flag && !cub->spr_flag)
		error_handler1(23);
	else
		return ;
}

int	everything_ok(t_structcub *cub)
{
	int		todo;

	if (!cub->t_north || !cub->t_west || !cub->t_east || !cub->t_south \
		|| !cub->t_sprite || !cub->screen.width || !cub->screen.height \
		|| !cub->f_hex || !cub->c_hex)
		todo = 0;
	else
		todo = 1;
	return (todo);
}
