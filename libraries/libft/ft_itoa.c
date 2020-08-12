/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:53:08 by mfalkrea          #+#    #+#             */
/*   Updated: 2019/09/20 12:09:08 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	n1;
	int				k;

	k = 0;
	n1 = ft_abs(n);
	if (n1 == 0)
		return (ft_strdup("0"));
	k = ft_intlen(n);
	if (n < 0)
		k++;
	s = ft_strnew(k);
	if (!s)
		return (NULL);
	k--;
	while (n1 > 0)
	{
		s[k] = '0' + n1 % 10;
		n1 = n1 / 10;
		k--;
	}
	if (k == 0)
		s[k] = '-';
	return (s);
}
