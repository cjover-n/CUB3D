/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:49:53 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/26 18:58:33 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*str;

	str = dst;
	while (*src != '\0' && n > 0)
	{
		*str++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*chg;
	size_t	i;
	size_t	x;

	chg = (char *)s1;
	if (chg == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (chg[i] && ft_strchr(set, chg[i]) != NULL)
		i++;
	x = ft_strlen(&chg[i]);
	if (x != 0)
	{
		while (chg[i + x - 1] && ft_strchr(set, s1[i + x - 1]) != NULL)
			x--;
	}
	if ((str = (char *)malloc(sizeof(char) * (x + 1))) == NULL)
		return (NULL);
	str = ft_strncpy(str, &chg[i], x);
	str[x] = '\0';
	return (str);
}
