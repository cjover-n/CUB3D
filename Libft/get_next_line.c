/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:53:03 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/23 01:18:04 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char		*stat[4096];
	char			*heap;
	char			buf[5];
	int				bytes;

	if (!stat[fd])
		stat[fd] = ft_strdup("");
	while ((bytes = read(fd, buf, 4)) > 0)
	{
		buf[bytes] = '\0';
		heap = ft_strjoin(stat[fd], buf);
		free(stat[fd]);
		if (ft_strchr((stat[fd] = heap), '\n'))
			break ;
	}
	if (bytes < 0 || line == NULL)
		return (-1);
	*line = ft_strcdup(stat[fd], '\n');
	heap = NULL;
	if (!(stat[fd][ft_strlen(*line)] == '\0'))
		heap = ft_strdup(ft_strchr(stat[fd], '\n') + 1);
	free(stat[fd]);
	stat[fd] = heap;
	if (stat[fd] == NULL)
		return (0);
	else
		return (1);
}
