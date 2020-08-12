/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:34:54 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/23 13:39:32 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*first;
	t_list	*second;

	if (alst)
	{
		first = *alst;
		while (first)
		{
			second = first->next;
			ft_lstdelone(&first, del);
			first = second;
		}
		*alst = NULL;
	}
}
