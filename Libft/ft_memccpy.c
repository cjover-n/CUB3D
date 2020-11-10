/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:53:23 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/17 20:25:37 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned const char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str1[i];
		if (str1[i] == (unsigned char)c)
			return ((void *)dst + i + 1);
		i++;
	}
	return (0);
}
