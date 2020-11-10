/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:28:03 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/01 14:29:50 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 2)))
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
