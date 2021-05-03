/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:25:52 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 21:11:03 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	x;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			x = 1;
			while (needle[x] != '\0' && haystack[i + x] == needle[x] \
				&& (size_t)(i + x) < len)
				++x;
			if (needle[x] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
