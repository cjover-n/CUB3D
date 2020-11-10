/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:41:09 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/17 21:36:28 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned const char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	while (i < n && (str1 || str2))
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
