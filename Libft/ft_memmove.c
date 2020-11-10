/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:15:14 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/10 16:03:08 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*str1;
	unsigned const char		*str2;
	size_t					i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (str2 < str1)
	{
		while (++i <= len)
			str1[len - i] = str2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(str1++) = *(str2++);
	}
	return (dst);
}
