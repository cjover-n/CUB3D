/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:49:27 by cjover-n          #+#    #+#             */
/*   Updated: 2019/12/08 22:58:49 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*nxt;

	if (lst && *lst && del)
	{
		aux = *lst;
		while (aux)
		{
			nxt = aux->next;
			ft_lstdelone(aux, del);
			aux = nxt;
		}
		*lst = 0;
	}
}
