/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:16:59 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/19 23:46:45 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)b;
	i = 0;
	if (len)
	{
		while (i != len)
		{
			p[i] = c;
			i++;
		}
	}
	return (b);
}
