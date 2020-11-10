/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:00:10 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/20 18:56:34 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1) + 1;
	if (!(mem = malloc((int)len)))
		return (NULL);
	ft_memcpy(mem, s1, len);
	return (mem);
}
