/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:53:03 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 19:18:44 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	static char		*stat[4096];
	char			*heap;
	char			buf[5];

	heap = NULL;
	if (!stat[fd])
		stat[fd] = ft_strdup("");
	gnl_normi(fd, buf, heap, stat);
	if (line == NULL)
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

int	gnl_normi(int fd, char buf[5], char *heap, char *stat[4096])
{
	int	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, 4);
		buf[bytes] = '\0';
		heap = ft_strjoin(stat[fd], buf);
		free(stat[fd]);
		stat[fd] = heap;
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	else
		return (0);
}
