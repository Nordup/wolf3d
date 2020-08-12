/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:03:06 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 11:45:49 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	i = 0;
	last = -1;
	c = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		last = i;
	if (last != -1)
		return ((char*)(s + last));
	else
		return (NULL);
}
