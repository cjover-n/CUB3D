/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:00:10 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 19:40:26 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1) + 1;
	mem = malloc((int)len);
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len);
	return (mem);
}
