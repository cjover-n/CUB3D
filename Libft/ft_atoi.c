/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:29:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/04/19 23:45:50 by cjover-n         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_stopspaces(const char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			flag;
	long int	num;

	i = 0;
	flag = 0;
	num = 0;
	i = ft_stopspaces(str, i);
	(str[i] == '-') && (flag = 1);
	(str[i] == '+' || str[i] == '-') && (i += 1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (num);
		num *= 10;
		(flag == 1) && (num -= str[i] - '0');
		(flag == 0) && (num += str[i] - '0');
		i++;
		if (num > 2147483647)
			return (-1);
		else if (num < -2147483648)
			return (0);
	}
	return (num);
}
