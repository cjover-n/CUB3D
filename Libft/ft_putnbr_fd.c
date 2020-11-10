/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:33:29 by cjover-n          #+#    #+#             */
/*   Updated: 2019/11/29 17:10:52 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	t;

	t = (long)n;
	if (t < 0)
	{
		ft_putchar_fd('-', fd);
		t = t * -1;
	}
	if (t > 9)
	{
		ft_putnbr_fd(t / 10, fd);
		ft_putnbr_fd(t % 10, fd);
	}
	else
	{
		ft_putchar_fd(t + '0', fd);
	}
}
