/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:53:39 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/13 19:10:21 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*mem;
	size_t	i;

	i = 0;
	mem = (void*)malloc(sizeof(*mem) * size);
	if (!mem)
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void*)mem);
}
