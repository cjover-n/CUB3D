/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:28:03 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/03 19:42:36 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		ret[0] = '-';
		ret[1] = '\0';
		ret = ft_strjoin(ret, ft_itoa(-n));
	}
	else if (n >= 10)
	{
		ret = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	}
	else if (n >= 0 && n <= 9)
	{
		ret[0] = n + '0';
		ret[1] = '\0';
	}
	return (ret);
}
