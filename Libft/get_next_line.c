/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:53:03 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/04 15:00:10 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error_fd(int rd)
{
	if (rd < 0)
		return (-1);
	return (rd);
}

static int	ft_convert_line(int rd, char **str, char **line)
{
	char	*tmp1;
	char	*tmp2;

	ft_error_fd(rd);
	if (!rd && !*str)
	{
		*line = ft_strdup("");
		return (0);
	}
	tmp1 = ft_strchr(*str, '\n');
	if (tmp1)
	{
		*tmp1 = '\0';
		*line = ft_strdup(*str);
		tmp2 = ft_strdup(++tmp1);
		free(*str);
		*str = tmp2;
	}
	else
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[5000];
	static char	*str;
	char		*tmp;
	int			rd;

	rd = 1;
	if (fd < 0 || !line || 5000 < 1)
		return (-1);
	while (rd > 0)
	{
		rd = read(fd, buff, 5000);
		buff[rd] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			tmp = (ft_strjoin(str, buff));
			free(str);
			str = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ft_convert_line(rd, &str, line));
}
