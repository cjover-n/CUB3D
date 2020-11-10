/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:36:00 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 21:27:41 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_flags1(t_tab *c)
{
	while (c->s[c->arr] == '0')
	{
		c->f_zero = 1;
		c->arr++;
	}
	if (c->s[c->arr] == ' ')
	{
		c->f_space = 1;
		ft_putchar_print(c, ' ');
		c->arr++;
	}
	if (c->s[c->arr] == '-')
	{
		c->f_hyphen = 1;
		c->arr++;
	}
	if (c->s[c->arr] == '+')
	{
		c->f_plus = 1;
		c->arr++;
	}
	ft_flags2(c);
}

void	ft_flags2(t_tab *c)
{
	if (ft_isdigit(c->s[c->arr]) == 1)
	{
		c->l = ft_atoi_print(c);
	}
	else if (c->s[c->arr] == '*')
	{
		c->f_astsk = 1;
		c->l = va_arg(c->list, int);
		c->arr++;
	}
	if (c->s[c->arr] == '.')
	{
		c->f_dot = 1;
		c->arr++;
	}
	if (c->s[c->arr] == '#')
	{
		c->f_pad = 1;
		c->arr++;
	}
	ft_flags3(c);
}

void	ft_flags3(t_tab *c)
{
	if (c->s[c->arr] >= '0' && c->s[c->arr] <= '9' && c->f_dot == 1)
		c->r = ft_atoi_print(c);
	else if (c->s[c->arr] == '*' && c->f_dot == 1)
	{
		c->r = va_arg(c->list, int);
		c->arr++;
	}
	if (c->s[c->arr] == '%')
	{
		c->f_percent = 1;
		ft_igor(c, "%");
		ft_miki(c);
		ft_putchar_print(c, '%');
		ft_alex(c);
		c->arr++;
	}
	if (c->f_percent <= 0)
		ft_types(c);
	else if (c->s[c->arr])
		ft_putchar_print(c, c->s[c->arr]);
}

void	ft_types(t_tab *c)
{
	if (c->s[c->arr] == ' ')
		c->arr++;
	if (c->s[c->arr] == 'c')
		ft_c(c);
	else if (c->s[c->arr] == 's')
		ft_s(c);
	else if (c->s[c->arr] == 'i' || c->s[c->arr] == 'd' || c->s[c->arr] == 'u'
		|| c->s[c->arr] == 'X' || c->s[c->arr] == 'x' || c->s[c->arr] == 'p'
		|| c->s[c->arr] == 'o')
		ft_id(c);
}
