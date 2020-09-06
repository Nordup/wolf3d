/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_atof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:47:54 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 11:48:13 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_atof(char const *s, double *number)
{
	int		i_w;
	int		i_f;
	int		whole;
	int		fract;

	i_f = 0;
	fract = 0;
	i_w = ft_count_atoi(s, &whole);
	if (s[i_w] == '.')
	{
		i_f = ft_count_atoi(s + i_w, &fract);
	}
	*number = whole + (double)fract / ft_pow(10, i_f);
	return (i_w + i_f);
}
