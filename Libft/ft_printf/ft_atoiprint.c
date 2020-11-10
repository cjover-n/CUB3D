/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:29:30 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 21:27:47 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_atoi_print(t_tab *c)
{
	long int	num;

	num = 0;
	while (c->s[c->arr] >= '0' && c->s[c->arr] <= '9')
	{
		num *= 10;
		num += c->s[c->arr] - '0';
		c->arr++;
		if (num > 2147483647)
			return (-1);
	}
	return (num);
}

int		ft_count(long unsigned int n, int base)
{
	long long int		ret;

	ret = 1;
	while (n / base > 0)
	{
		ret++;
		n = n / base;
	}
	return (ret);
}

int		ft_countneg(long int n, int base)
{
	long long int		ret;

	ret = 1;
	while (n / base < 0)
	{
		ret++;
		n = n / base;
	}
	return (ret);
}

char	*ft_itoabase(t_tab *c)
{
	if (c->s[c->arr] == 'i' || c->s[c->arr] == 'd' || c->s[c->arr] == 'u')
		c->itoa_base = 10;
	if (c->s[c->arr] == 'x' || c->s[c->arr] == 'X' || c->s[c->arr] == 'p')
		c->itoa_base = 16;
	c->s[c->arr] == 'o' ? c->itoa_base = 8 : 0;
	if (c->s[c->arr] == 'i' || c->s[c->arr] == 'd')
		c->itoa_n = va_arg(c->list, int);
	else if (c->s[c->arr] == 'p')
		c->itoa_n = va_arg(c->list, long unsigned int);
	else
		c->itoa_n = va_arg(c->list, unsigned int);
	if (c->itoa_n >= 0)
		c->itoa_pos = ft_count(c->itoa_n, c->itoa_base);
	else
		c->itoa_pos = ft_countneg(c->itoa_n, c->itoa_base);
	if (!(c->itoa_ret = (char *)malloc(sizeof(char) * c->itoa_pos + 1)))
		return (NULL);
	ft_itoabase_logic(c);
	return (c->itoa_ret);
}

void	*ft_itoabase_logic(t_tab *c)
{
	c->itoa_ret[c->itoa_pos--] = '\0';
	while (c->itoa_pos >= 0)
	{
		if (c->itoa_n < 0)
		{
			c->itoa_neg = 1;
			c->itoa_n = c->itoa_n * -1;
		}
		if ((c->itoa_n % c->itoa_base <= 9) && (c->itoa_n >= 0))
			c->itoa_ret[c->itoa_pos] = c->itoa_n % c->itoa_base + '0';
		else if ((c->itoa_n % c->itoa_base > 9) && c->s[c->arr] == 'X')
			c->itoa_ret[c->itoa_pos] = c->itoa_n % c->itoa_base + 55;
		else
			c->itoa_ret[c->itoa_pos] = c->itoa_n % c->itoa_base + 87;
		c->itoa_n = c->itoa_n / c->itoa_base;
		c->itoa_pos--;
	}
	return (c->itoa_ret);
}
