/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:35:55 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 21:27:46 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_c(t_tab *c)
{
	int f;

	f = va_arg(c->list, int);
	if (c->l > 1 && c->f_hyphen <= 0)
	{
		c->f_igor = c->l - 1;
		while (c->f_igor-- > 0)
			ft_putchar_print(c, ' ');
	}
	else if (c->f_hyphen > 0)
	{
		ft_putchar_print(c, f);
		c->f_igor = c->l - 1;
		while (c->f_igor-- > 0)
		{
			ft_putchar_print(c, ' ');
		}
		return ;
	}
	ft_putchar_print(c, f);
	ft_initialize(c);
}

void	ft_s(t_tab *c)
{
	char	*str;

	if (!(str = va_arg(c->list, char *)))
		str = "(null)";
	ft_igor(c, str);
	if (c->f_dot == 0)
		ft_miki(c);
	ft_putstr_pre(c, str);
	if (c->f_astsk > 0 && c->l < 0)
		c->f_igor = (c->l * -1) - ft_strlen(str);
	ft_alex(c);
}

void	ft_id(t_tab *c)
{
	char	*str;

	str = ft_itoabase(c);
	ft_igor(c, str);
	if (c->itoa_neg > 0)
		ft_putchar_print(c, '-');
	else if (c->f_plus > 0)
		ft_putchar_print(c, '+');
	if (c->f_zero > 0 && c->f_dot > 0 && c->r < (int)ft_strlen(str))
		c->f_miki = 0;
	ft_miki(c);
	c->r < 0 ? c->r = c->r * -1 : 0;
	ft_putstr_pre(c, str);
	if (c->f_astsk > 0 && c->l < 0)
		c->f_igor = (c->l * -1) - ft_strlen(str);
	if (c->f_astsk > 0 && c->l < 0 && c->itoa_neg > 0)
		c->f_igor = c->f_igor - 1;
	ft_alex(c);
}
