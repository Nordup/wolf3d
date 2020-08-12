/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:59:42 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/15 14:17:54 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_size;
	size_t i;

	i = 0;
	dest_size = ft_strlen(dest);
	if (size < (size_t)dest_size + 1)
		return ((size_t)ft_strlen((char*)src) + size);
	while (i + dest_size < size - 1 && src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + (size_t)ft_strlen((char*)src));
}
