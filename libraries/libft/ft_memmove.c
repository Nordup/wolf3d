/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:55:19 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 12:16:47 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;
	size_t	i;

	i = 0;
	t_src = (char*)src;
	t_dst = (char*)dst;
	if (!t_src && !t_dst)
		return (NULL);
	if (t_src < t_dst)
		while (len > 0)
		{
			len--;
			t_dst[len] = t_src[len];
		}
	else
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	return (dst);
}
