/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:01:19 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/02 20:27:51 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counting_charsets(const char *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char		*ft_strndup(char const *s1, size_t n)
{
	char	*clone;
	size_t	i;

	if ((clone = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

static void		*ft_destroy(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *str, char charset)
{
	char	**ret;
	size_t	tab;
	size_t	i;
	size_t	x;

	if (str == NULL)
		return (NULL);
	tab = ft_counting_charsets(str, charset);
	if ((ret = (char **)malloc(sizeof(char *) * (tab + 1))) == NULL)
		return (NULL);
	tab = 0;
	x = -1;
	while (str[++x])
	{
		if (str[x] == charset)
			continue;
		i = 0;
		while (str[x + i] && str[x + i] != charset)
			i++;
		if ((ret[tab++] = ft_strndup(&str[x], i)) == NULL)
			return (ft_destroy(ret));
		x += i - 1;
	}
	ret[tab] = NULL;
	return (ret);
}
