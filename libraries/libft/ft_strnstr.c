/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:02:44 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 13:59:38 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen((char*)needle))
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len
			&& (i + ft_strlen((char*)needle)) <= len)
	{
		if (haystack[i] == needle[0] && !ft_strncmp((char*)(haystack + i),
					needle, ft_strlen((char*)needle)))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
