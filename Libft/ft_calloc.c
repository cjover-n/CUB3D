/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:46:04 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/19 18:45:27 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	n;

	n = count * size;
	str = malloc(n);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (str)
		ft_bzero(str, n);
	return (str);
}
