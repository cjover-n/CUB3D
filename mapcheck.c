/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:55:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/14 19:30:00 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line, t_structcub *cub)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == 'N' \
			|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == ' ')
		{
			cub->isline = 1;
			if (line[i] == '2')
			{
				cub->spr.found++;
				line[i] = '?';
			}
			is_map_player(line, cub, i);
			flood_prepare(line, i);
			cub->map_len = ft_strlen(line);
		}
		else
			return (0);
		i++;
	}
	return (cub->isline);
}

void	flood_prepare(char *line, int i)
{
	if (line[i] == '0' || line[i] == 'N' || line[i] == 'S' \
		|| line[i] == 'W' || line[i] == 'E')
		line[i] = 33;
}

void	is_map_player(char *line, t_structcub *cub, int i)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
		|| line[i] == 'E')
	{
		if (cub->player.player_ok == 0)
			get_player(cub, line[i], i);
		else
			error_handler1(10);
	}
}

void	get_map(t_structcub *cub, char *line, char **buffer)
{
	char	*temp;
	char	*temp2;

	if (*buffer == 0)
		*buffer = ft_strdup("");
	temp = ft_strjoin(line, ".");
	temp2 = ft_strjoin(*buffer, temp);
	free(temp);
	free(*buffer);
	*buffer = ft_strdup(temp2);
	free(temp2);
	cub->line_counter++;
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
