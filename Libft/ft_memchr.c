/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:56:19 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/18 17:20:37 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
