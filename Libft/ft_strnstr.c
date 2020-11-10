/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:25:52 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/18 22:05:33 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int x;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			x = 1;
			while (needle[x] != '\0' && haystack[i + x] == needle[x] &&
			(size_t)(i + x) < len)
				++x;
			if (needle[x] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
