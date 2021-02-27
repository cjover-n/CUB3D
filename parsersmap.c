/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsersmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:56:29 by cjover-n          #+#    #+#             */
/*   Updated: 2021/02/27 20:31:27 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			resolution_parser(char *line, t_structcub *cub, t_errors *error)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	if (ft_isdigit(line[i]))
	{
		cub->screen.width = ft_atoi(&line[i]);
		i = ft_numlen(cub->screen.width) + 3;
		if (ft_isdigit(line[i]) == 1)
			cub->screen.height = ft_atoi(&line[i]);
	}
	else
	{
		error->resolution = 1;
		error_handler1(cub, error);
	}
}

char			*texture_parser(char *arr, t_structcub *cub, t_errors *error)
{
	while (*arr != '.' && *arr != '\0')
		arr++;
	if (*arr != '.')
	{
		error->badtexture = 1;
		error_handler1(cub, error);
		return (NULL);
	}
	return (ft_strdup(arr));
}

unsigned int	color_parser(char *line)
{
	int				i;
	int				x;
	int				color[3];
	unsigned int	ret;

	i = 1;
	x = 0;
	i = space_checker(line, i);
	while (ft_isdigit(line[i]) && x < 3)
	{
		if (ft_isdigit(line[i]))
		{
			color[x] = ft_atoi(&line[i]);
			if (rgb_range(color[x]) == 0)
				ft_printf("Error\nRango de color mal\n");
			i = i + ft_numlen(color[x]);
		}
		else
			ft_printf("Error\n Color mal\n");
		if (line[i] == ',' || x == 2)
			i++;
		else
			ft_printf("Error\n Comas mal\n");
		x++;
	}
	ret = create_trgb(0, color[0], color[1], color[2]);
	return (ret);
}

int				is_map_line(char *line, t_structcub *cub, t_errors *error)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
		{
			cub->isline = 1;
			if (line[i] == '0')
				line[i] = 33;
			//flood_check(cub, cub->pos_y, cub->pos_x);
			if (line[i] == '2')
				cub->spr.found++;
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			{
				if (cub->player.player_ok == 0)
					get_player(cub, line[i], i, error);
				else
				{
					error->toomanyplayers = 1;
					error_handler1(cub, error);
					exit(0);
				}
			}
			cub->map_len = ft_strlen(line);//tener en cuenta que solo está almacenando ahora mismo el largo de la ÚLTIMA línea
		}
		else
			cub->isline = 0;
		i++;
	}
	return (cub->isline);
}

void			get_map(t_structcub *cub, char *line, char **buffer)
{
	char *temp;

	if (*buffer == 0)
		*buffer = ft_strdup(line);
	else
	{
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, ".");
		free(temp);
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, line);
		free(temp);
	}
	cub->line_counter++;
}
