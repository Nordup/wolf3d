/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:03:50 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/19 12:41:50 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[len - 1] == ' ' ||
			s[len - 1] == '\n' || s[len - 1] == '\t') && len > 0)
		len--;
	new = ft_strnew((len > i) ? (len - i) : 0);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[j++] = s[i++];
		new[j] = '\0';
	}
	return (new);
}
