/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:55 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 21:27:44 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_miki(t_tab *c)
{
	if (c->itoa_neg > 0 && c->f_dot == 0)
		c->f_miki--;
	if (c->s[c->arr] == 'p' && c->f_miki > 0 && c->r && c->f_dot > 0)
	{
		c->f_signpointer = 1;
		write(1, "0x", 2);
		c->len = c->len + 2;
	}
	while (c->f_miki-- > 0)
	{
		ft_putchar_print(c, '0');
	}
}

void	ft_igor(t_tab *c, char *str)
{
	if (c->s[c->arr] != 's' && (c->f_miki = c->r - ft_strlen(str)) < 0)
		c->f_miki = 0;
	else if (c->s[c->arr] == 's' && (c->f_miki = c->r) > (int)ft_strlen(str))
		c->f_miki = 0;
	if ((c->f_igor = c->l - c->f_miki - (int)ft_strlen(str)) < 0)
		c->f_igor = 0;
	else if (c->s[c->arr] == 'p' && str != NULL)
		c->f_igor = c->f_igor - 2;
	if (c->s[c->arr] == 's' && ((c->r > (int)ft_strlen(str) ||
		(c->r == 0 && c->f_dot == 0))))
		c->r = (int)ft_strlen(str);
	if ((c->s[c->arr] == 's' && ((c->f_igor = c->l - c->r) < 0)) || c->r < 0)
		c->f_igor = 0;
	if (c->f_zero && c->f_hyphen <= 0 && c->f_dot <= 0 &&
		c->l > (int)ft_strlen(str))
	{
		c->f_miki = c->f_igor;
		c->f_igor = 0;
	}
	if (c->f_zero && c->f_hyphen <= 0 && c->f_dot > 0 &&
		ft_strncmp(str, "0", 1) <= 0)
		c->f_miki = c->f_miki - 1;
	if (c->itoa_neg > 0)
		c->f_igor--;
	ft_coco(c, str);
}

void	ft_coco(t_tab *c, char *str)
{
	if (c->f_hyphen == 0)
	{
		if (c->f_zero == 1 && c->f_dot == 1)
		{
			c->f_igor = c->l - c->r;
			if (c->itoa_neg > 0 && c->l > (int)ft_strlen(str))
			{
				c->f_igor--;
				c->f_miki = c->l - c->r - (int)ft_strlen(str);
			}
			if (c->r < (int)ft_strlen(str))
				c->f_igor--;
		}
		c->f_plus > 0 ? c->f_igor-- : 0;
		while (c->f_igor-- > 0)
			ft_putchar_print(c, ' ');
	}
}

void	ft_alex(t_tab *c)
{
	if (c->f_hyphen > 0 || c->f_astsk > 0)
	{
		while (c->f_igor-- > 0)
		{
			ft_putchar_print(c, ' ');
		}
	}
}

void	ft_hexadecimal(t_tab *c, const char *str)
{
	int i;

	i = 0;
	if (c->f_signpointer == 0)
	{
		if (c->s[c->arr] == 'p' || (c->s[c->arr] == 'x' && c->f_pad == 1))
		{
			write(1, "0x", 2);
			c->len = c->len + 2;
		}
	}
	if (c->s[c->arr] == 'X' && c->f_pad == 1)
	{
		write(1, "0X", 2);
		c->len = c->len + 2;
		while (str[i] != '\0' && (c->r-- || c->s[c->arr] != 's'))
		{
			ft_toupper(write(1, &str[i], 1));
			c->len++;
			i++;
		}
		return ;
	}
}
