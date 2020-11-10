/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:53:37 by cjover-n          #+#    #+#             */
/*   Updated: 2020/09/29 00:32:50 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnew(size_t size)
{
    char    *str;

    if (!(str = (char *)malloc(sizeof(char) * size + 1)))
        return (NULL);
    str[size] = '\0';
    while (size--)
        str[size] = '\0';
    return (str);
}
