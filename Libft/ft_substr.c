/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:30:09 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 21:12:43 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*new;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (count < len)
	{
		new[count] = s[start + count];
		count++;
	}
	new[count] = '\0';
	return (new);
}
