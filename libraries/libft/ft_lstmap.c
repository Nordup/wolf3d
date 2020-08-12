/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:50:33 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/23 14:57:21 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*now;

	if (!lst)
		return (NULL);
	if (!(new = (*f)(lst)))
	{
		ft_lstdel(&new, &ft_dellist);
		return (NULL);
	}
	now = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(now->next = (*f)(lst)))
		{
			ft_lstdel(&new, &ft_dellist);
			return (NULL);
		}
		now = now->next;
	}
	return (new);
}
