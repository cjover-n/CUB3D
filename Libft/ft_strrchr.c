/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:06:06 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/25 20:14:57 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*aux;

	aux = NULL;
	if (!str)
	{
		while (str)
			str++;
		str++;
	}
	while (str)
	{
		if (*str == c)
			aux = (char *)str;
		if (!*str)
			return (aux);
		str++;
	}
	return (aux);
}
