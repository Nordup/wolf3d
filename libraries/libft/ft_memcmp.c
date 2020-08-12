/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:54:31 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/13 19:13:18 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*t1;
	char	*t2;

	i = 0;
	t1 = (char*)s1;
	t2 = (char*)s2;
	while (i < n)
	{
		if (t1[i] == t2[i])
			i++;
		else
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
	}
	return (0);
}
