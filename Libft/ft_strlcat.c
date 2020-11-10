/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:34:44 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/03 18:32:39 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (dest[i] && i < size)
		i++;
	while (src[y] && (y + i + 1) < size)
	{
		dest[i + y] = src[y];
		y++;
	}
	if (i < size)
		dest[i + y] = '\0';
	return (i + ft_strlen(src));
}
