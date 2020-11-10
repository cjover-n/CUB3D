/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:52:31 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/03 21:36:37 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		new->content = content;
	else
	{
		if (!(new->content = malloc(sizeof(content))))
			return (NULL);
		new->content = content;
	}
	new->next = NULL;
	return (new);
}
