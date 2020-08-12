/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:54:01 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 11:43:46 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	i = 0;
	t_src = (unsigned char*)src;
	t_dest = (unsigned char*)dest;
	while (i < n)
	{
		t_dest[i] = t_src[i];
		if (t_src[i] == (unsigned char)c)
		{
			return (dest + i + 1);
			break ;
		}
		i++;
	}
	return (NULL);
}
