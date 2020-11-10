/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:49:13 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 21:32:51 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printf(const char *format, ...)
{
	t_tab	c;

	va_start(c.list, format);
	c.s = format;
	c.arr = 0;
	c.len = 0;
	while (c.s[c.arr])
	{
		ft_initialize(&c);
		if (c.s[c.arr] == '%')
		{
			c.arr++;
			ft_flags1(&c);
		}
		else
		{
			ft_putchar_print(&c, c.s[c.arr]);
		}
		if (c.s[c.arr])
			c.arr++;
	}
	va_end(c.list);
	return (c.len);
}
